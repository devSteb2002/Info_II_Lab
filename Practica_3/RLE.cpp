#include "Definition.h"
#include <fstream>

using namespace std;

string* initRLE(int &rows_);
void readFile(string name, string type,  string *& compresions, int & rows);
void comprimRLe(string chain,  string *& compresions, int* index);
void descomRLe(string &chain);
void addElement(string *& compresions, int * index, string* value);

string *initRLE(int &rows_ ){
    string *compresions = nullptr;
    int rows = 0;

    readFile("Texto", "txt", compresions, rows);

    for (int i = 0; i < rows; i++){
        descomRLe(compresions[i]);
    }
    rows_ = rows;
    return compresions;
}

void readFile(string name, string type, string *&compresions, int &rows){
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
            count++;
            comprimRLe(line, compresions, &count);
        }

        File.close();

    } catch (const ios_base ::failure& e ){
        cout << "Error al manejar el archivo: " << e.what() << endl;
    }

    rows = count;
}

void comprimRLe(string chain, string *& compresions, int* index){
    string comprim = "";

    for (short i = 0; i < chain.length(); i++){
        int count = 1;

        while (i + 1 < chain.length() && tolower(chain[i]) == tolower(chain[i + 1])){
            count++;
            i++;
        }

        comprim += to_string(count) + chain[i];
    }

    addElement(compresions, index , &comprim);
}

void descomRLe(string &chain){

    string descom = "";

    for (int i = 0; i < chain.length(); i++){
        if (isdigit(chain[i])){
            const int numberOfCaracter = chain[i] - '0';
            const char letter = chain[i + 1];

            for (short  f = 0; f < numberOfCaracter; f++){
                descom += letter;
            }

            i++;
        }
    }
}

void addElement(string *& compresions, int *index, string *value){

    if (compresions == nullptr){
        compresions = new string[*index + 1];
        compresions[*index - 1] = *value;
        return;
    }

    string * newArray = new string[*index];

    for (int i = 0; i < *index; i++){
        newArray[i] = compresions[i];
    }

    newArray[*index - 1] = *value;

    delete[] compresions;
    compresions = newArray;
}
