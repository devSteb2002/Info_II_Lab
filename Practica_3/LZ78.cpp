#include <fstream>
#include <iostream>

using namespace std;
void readFileLZ(string name, string type,  char ***& JSON, int & rows, int& cols_);
void generateJSON(string chain,  char***& JSON, int* rows, int& cols);
void addRowToDicc(char **& JSONLine, int &JSONRows);
void addRowToJson(char ***& JSON, const int rows);
void saveDataLZ78(std::string type, const string *data, const int & rows);


char ***initLZ78(int &rows, const string type, int &cols){

        char ***JSON = nullptr;
        int rows_ = 0;
        int cols_  = 0;

        readFileLZ("Texto", "txt", JSON, rows_, cols_);
        rows = rows_;
        cols = cols_;

        return JSON;
}

void readFileLZ(string name, string type, char ***&JSON, int &rows, int &cols_){
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

void generateJSON(string chain,  char ***& JSON, int* rows, int &cols){

    char **JSONLine = nullptr;
    int       JSONrows = 0;

    for (int i = 0; i < chain.length(); i++){
        if (JSONLine == nullptr){
            addRowToDicc(JSONLine, JSONrows);
            JSONLine[0] = new char[2];
            JSONLine[0][0] = '0';
            JSONLine[0][1] = chain[i];
            continue;
        };

        //buscamos si ya existe en el diccionario
        bool findLetter = false;

        for (int row = 0; row < JSONrows; row++){
            if (JSONLine[row][1] == chain[i])  findLetter = true;
        }

        addRowToDicc(JSONLine, JSONrows);
        JSONLine[JSONrows - 1] = new char[2];

        if (!findLetter){ // no encontro, entonces se expande el array y se ingresa la letra
            JSONLine[JSONrows - 1][0] = '0';
            JSONLine[JSONrows - 1][1] = chain[i];
        }
        else { // se encotro, se expande el array y se hace iteracion hasta llegar a una palabra que no este en JSON

            int     indexFinded = 0;
            char actualLetter = chain[i];
            char nextLetter = i + 1 >= chain.length() ? actualLetter :  chain[i + 1] ;

            for (int item = 0; item < JSONrows; item++){
                if (JSONLine[item][1] == actualLetter){
                    indexFinded = item + 1;
                    break;
                }
            }

            JSONLine[JSONrows - 1][0] = '0' + indexFinded;
            JSONLine[JSONrows - 1][1] = nextLetter;

            i++;

        }
    }

   cols = JSONrows;
   JSON[*rows] = JSONLine;

}


void descomLZ78(char ***JSON, const int &rows, short * cols){

    string listOfWords[rows];
    bool isFails = false;

    for (short i = 0; i < rows; i++){

        string word = "";

        for (short c = 0; c < cols[i]; c++){
            try {
                const unsigned char indice = JSON[i][c][0];
                const unsigned char letter = JSON[i][c][1];

                if (indice == '0') {
                    word += letter;

                    continue;
                }

                if (indice < '0' || indice > '9') {
                    throw runtime_error("Indice no es un dígito válido");
                }

                short indexFind = static_cast<short>(indice) - '0';
                char findedLetter = JSON[i][indexFind - 1][1];

                word = word + findedLetter + JSON[i][c][1];
            }
            catch (const std::exception &e) {
                isFails = true;
            }
        }

        listOfWords[i] = word;
    }

    if (isFails){
        cout << "Fallo en la desencriptacion, clave n incorrecta." << endl;
        return;
    }

    saveDataLZ78("decrypt", listOfWords, rows);
}

string *gettDataLZ78(int & rows){
    string *data = nullptr;
    ifstream File;
    string line;
    int count = 0;
    int indix = 0;

    try {
        File.exceptions(ifstream::badbit);
        File.open("LZ78_encrypts.txt", ios::binary);

        if (!File.is_open()){
            cout << "No se pudo abrir el archivo" << endl;
            return nullptr;
        }

        while(getline(File, line))count++;

        File.clear();
        File.seekg(0);
        data = new string[count];

        while (getline(File, line)) {
            data[indix] = line;
            indix++;
        }

        File.close();

    } catch (const ios_base ::failure& e ){
        cout << "Error al manejar el archivo: " << e.what() << endl;
    }

    rows = count;
    return data;

}

void generateJSONDecrypt(char **&JSON, int& cols, const char &indice, const char &letter){

     addRowToDicc(JSON, cols);

     JSON[cols - 1] = new char[2];
     JSON[cols - 1][0] = indice;
     JSON[cols -1][1] = letter;

}

void addRowToDicc(char **& JSONLine, int &JSONRows){
    if (JSONLine == nullptr){
        JSONLine = new char*[JSONRows + 1];
        JSONRows++;
        return;
    }

   char **newArray = new char*[JSONRows + 1];

    for (int i = 0; i < JSONRows; i++){
        newArray[i] = JSONLine[i];
    }


    delete[] JSONLine;

    JSONLine = newArray;
    JSONRows++;
}


void addRowToJson(char ***& JSON, const int rows){
    if (JSON == nullptr){
        JSON = new char**[rows + 1];
        return;
    }

    char ***newArray = new char**[rows + 1];

    for (int i = 0; i < rows; i++){
        newArray[i] = JSON[i];
    }

    delete[] JSON;
    JSON = newArray;
}

void saveDataLZ78(std::string type, const string *data, const int & rows){
    string nameFile = "";
    if (type == "decrypt") nameFile = "LZ78_decrypt.txt";
    else nameFile = "LZ78_encrypts.txt";

    ofstream file(nameFile, ios::binary);

    for (short i = 0; i < rows; i++){
        file << data[i] << '\n';
    }

}

