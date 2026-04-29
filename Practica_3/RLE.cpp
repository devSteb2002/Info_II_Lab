#include "Definition.h"
#include <fstream>

using namespace std;

string* initRLE(int &rows_);
void readFile(string name, string type,  string *& compresions, int & rows);
void saveData(string type, string *dataToEncryptRLE, int &rows);
void comprimRLe(string chain,  string *& compresions, int* index);
void descomRLe(string &chain);
void addElement(string *& compresions, int * index, string* value);
std::string* getDataEncrypt();

string *initRLE(int &rows_ ){
    string *compresions = nullptr;
    int rows = 0;

    readFile("Texto", "txt", compresions, rows);

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

        comprim = comprim + to_string(count) + chain[i];
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

    chain = descom;

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

void saveData(string type, string *dataToEncryptRLE, int&rows){
    string nameFile = "";
    if (type == "decrypt") nameFile = "RLE_decrypt.txt";
    else nameFile = "RLE_encrypts.txt";

    ofstream file(nameFile, ios::binary);

    for (short i = 0; i < rows; i++){
        file << dataToEncryptRLE[i] << '\n';
    }

}

std::string* getDataEncrypt(int &rows){
    string *compresions = nullptr;

    ifstream File;
    string line;
    int count = 0;

    try {

        File.exceptions(ifstream::badbit);
        File.open("RLE_encrypts.txt");

        if (!File.is_open()){
            cout << "No se pudo abrir el archivo" << endl;
            return nullptr;
        }

        while (getline(File, line)){
            count++;
            addElement(compresions, &count, &line);
        }

        File.close();

    } catch (const ios_base ::failure& e ){
        cout << "Error al manejar el archivo: " << e.what() << endl;
    }

    rows = count;

    return compresions;
}
