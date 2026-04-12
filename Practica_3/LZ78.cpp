#include "Definition.h"
#include <fstream>

using namespace std;

string ***initLZ78(int &rows, const string type);
void readFileLZ(string name, string type,  string ***& JSON, int & rows, int& cols_);
void generateJSON(string chain,  string***& JSON, int* rows, int& cols);
void descomLZ78(const string*** JSON, const int *rows, const int* cols);
void addRowToDicc(string **& JSONLine, int &JSONRows);
void addRowToJson(string ***& JSON, const int rows);

string ***initLZ78(int &rows, const string type){

        string ***JSON = nullptr;
        int rows_ = 0;
        int cols_  = 0;

        readFileLZ("TextoLZ78", "txt", JSON, rows_, cols_);

        cout << rows_  << "  " << cols_ << endl;

        return JSON;

}


void readFileLZ(string name, string type, string ***&JSON, int &rows, int &cols_){
    ifstream File;
    string line;
    int count = 0;

    try {
        File.exceptions(ifstream::badbit);
        File.open(name + "." + type);

        if (!File.is_open()){
            cout << "No se pudo abrir el archivo" << endl;
            return;
        }

        while (getline(File, line)){
            addRowToJson(JSON, count);
            generateJSON(line, JSON, &count, cols_);
            count++;

        }

        File.close();

    } catch (const ios_base ::failure& e ){
        cout << "Error al manejar el archivo: " << e.what() << endl;
    }

    rows = count;
}

void generateJSON(string chain,  string ***& JSON, int* rows, int &cols){

    string **JSONLine = nullptr;
    int       JSONrows = 0;

    for (int i = 0; i < chain.length(); i++){
        if (JSONLine == nullptr){
            addRowToDicc(JSONLine, JSONrows);
            JSONLine[0] = new string[2];
            JSONLine[0][0] = to_string(0);
            JSONLine[0][1] = chain[i];
            continue;
        };

        //buscamos si ya existe en el diccionario
        bool findLetter = false;

        for (int row = 0; row < JSONrows; row++){
            if (JSONLine[row][1] == string(1, chain[i]))  findLetter = true;
        }

        addRowToDicc(JSONLine, JSONrows);
        JSONLine[JSONrows - 1] = new string[2];

        if (!findLetter){ // no encontro, entonces se expande el array y se ingresa la letra
            JSONLine[JSONrows - 1][0] = to_string(0);
            JSONLine[JSONrows - 1][1] = chain[i];
        }
        else { // se encotro, se expande el array y se hace iteracion hasta llegar a una palabra que no este en JSON

            int     indexFinded = 0;
            string actualLetter = string(1, chain[i]);
            string nextLetter = i + 1 >= chain.length() ? actualLetter : string(1, chain[i + 1]) ;

            for (int item = 0; item < JSONrows; item++){
                if (JSONLine[item][1] == actualLetter){
                    indexFinded = item + 1;
                    break;
                }
            }

            JSONLine[JSONrows - 1][0] = to_string(indexFinded);
            JSONLine[JSONrows - 1][1] = nextLetter;

            i++;

        }
    }

  for (int i = 0; i < JSONrows; i++){
        cout << "   " << JSONLine[i][0] << ": " << JSONLine[i][1] << endl;
    }

   cols = JSONrows;
   JSON[*rows] = JSONLine;

}


void descomLZ78(const string*** JSON, const int *rows, const int* cols){



}

void addRowToDicc(string **& JSONLine, int &JSONRows){
    if (JSONLine == nullptr){
        JSONLine = new string*[JSONRows + 1];
        JSONRows++;
        return;
    }

    string **newArray = new string*[JSONRows + 1];

    for (int i = 0; i < JSONRows; i++){
        newArray[i] = JSONLine[i];
    }

    newArray[JSONRows] = nullptr;

    delete[] JSONLine;

    JSONLine = newArray;
    JSONRows++;
}


void addRowToJson(string ***& JSON, const int rows){
    if (JSON == nullptr){
        JSON = new string**[rows + 1];
        return;
    }

    string ***newArray = new string**[rows + 1];

    for (int i = 0; i < rows; i++){
        newArray[i] = JSON[i];
    }

    delete[] JSON;
    JSON = newArray;
}
