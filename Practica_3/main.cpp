#include "Definition.h"

using namespace std;

enum Algoritm { RLE, LZ78 };
enum typeProces { ENCRYPT, DECRYPT };

unsigned char rotarIzquierda(unsigned char byte, int n);
unsigned char rotarDerecha(unsigned char byte, int n);

int main()
{
    cout << "=======================" <<  endl;
    cout << "Practica # 3 " << endl;
    cout << "=======================" <<  endl;

    string option = "";
    Algoritm algoritm;
    typeProces Proces;
    bool  endedSystem = false;
    short n;
    const short k = 3;

    if (option == "3") return 0;

    do {
        cout << "Encriptacion    -> opcion 1" << endl;
        cout << "Desencriptacion -> opcion 2" << endl;
        cout << "Salir           -> opcion 3" << endl;

        cout << "Seleccione la accion: ";
        getline(cin, option);

        bool isValid = true;

        for (char c: option){
            if (!isdigit(c)){
                cout << "Tipo de dato invalido, vuelva a intentar." << endl;
                isValid = false;
                break;
            }
        }

        if (!isValid) continue;

        if (stoi(option) > 3 || stoi(option) < 1){
            cout << "Solo hay tres opciones, vuelva a intentar." << endl;
            continue;
        }

        if (stoi(option) == 3) {
            endedSystem = true;
            break;
        }

        if (option == "1")  Proces = ENCRYPT;
        else if (option ==  "2") Proces = DECRYPT;

        do {
                cout << "Ingres un numero entre 1 y 7: ";
                getline(cin, option);

                bool isValid = true;

                for (char c: option){
                    if (!isdigit(c)){
                        cout << "Tipo de dato invalido, vuelva a intentar." << endl;
                        isValid = false;
                        break;
                    }
                }

                 if (!isValid) continue;

                 if (stoi(option) > 7 || stoi(option) < 1){
                     cout << "El rango es entre 1 y 7." << endl;
                     continue;
                }

                 n = stoi(option);
                break;

        } while (true);


        cout << "RLE   -> opcion 1" << endl;
        cout << "LZ78 ->  opcion 2" << endl;

        do {
            cout << "Seleccione el metodo de compresion: ";
            getline(cin, option);

            bool isValid = true;

            for (char c: option){
                if (!isdigit(c)){
                    cout << "Tipo de dato invalido, vuelva a intentar." << endl;
                    isValid = false;
                    break;
                }
            }

            if (!isValid) continue;

            if (stoi(option) > 2 || stoi(option) < 1){
                cout << "Solo hay dos opciones, vuelva a intentar." << endl;
                continue;
            }

            break;

        } while (true);


        break;
    } while(true);


    if (endedSystem) return 0;


    string *dataToEncryptRLE = nullptr;
    char ***dataToEncryptLZ78 = nullptr;
    int rows = 0;
    int cols = 0;

    if (option == "1")algoritm = RLE;
    else algoritm = LZ78;

    if (algoritm == RLE && Proces == ENCRYPT){
        dataToEncryptRLE = initRLE(rows);

        for (short i = 0; i < rows; i++){
            for (char &c: dataToEncryptRLE[i]){
                unsigned char byte = static_cast<unsigned char>(c);
                byte = rotarIzquierda(byte, n);
                byte = byte ^ k;
                c = static_cast<char>(byte);
            }
        }

        saveData("encrypt", dataToEncryptRLE, rows);
    }
    else if (algoritm == RLE && Proces == DECRYPT){
        int rows_;
        string *dataToDecryptRLE = getDataEncrypt(rows_);

        for (short i = 0; i < rows_; i++){
            for (char &c: dataToDecryptRLE[i]){
                unsigned char byte = static_cast<unsigned char>(c);
                 byte = byte ^ k;
                byte = rotarDerecha(byte, n);
                c = static_cast<char>(byte);
            }

            descomRLe(dataToDecryptRLE[i]);
            saveData("decrypt", dataToDecryptRLE, rows_);
        }


        delete[] dataToDecryptRLE;
    }
    else if (algoritm == LZ78 && Proces == ENCRYPT){
        dataToEncryptLZ78 = initLZ78(rows, "encrypt", cols);
        string encrypted[rows];

        for (short i = 0; i < rows; i++){
            string line = "";

            for (short f = 0; f < cols; f++){
                unsigned char indice =  dataToEncryptLZ78[i][f][0];
                unsigned char letter =  dataToEncryptLZ78[i][f][1];
                const unsigned char blank = ':';
                const unsigned char space = ';';

                indice = rotarIzquierda(indice, n);
                letter = rotarIzquierda(letter, n);

                indice = indice ^ k;
                letter = letter ^ k;

                line += to_string((int)indice);
                line += ':';
                line += to_string((int)letter);
                line += ';';

            }

            encrypted[i] = line;
        }

        saveDataLZ78("encrypt", encrypted, rows);
    }
    else if (algoritm == LZ78 && Proces == DECRYPT){
        string* data = gettDataLZ78(rows);
        char ***arrayOfJson = new char**[rows];
        short colss[rows];

        for (short i = 0; i < rows; i++){

            string token;
            cols = 0;

            for (short f = 0; f < data[i].length(); f++){
                if (data[i][f] == ';'){
                    cols++;
                }
            }

            char **JSON = new char*[cols];

            colss[i] = cols;
            short index = 0;

            for (short f = 0; f < data[i].length(); f++){
                if (data[i][f] == ';'){

                    size_t pos = token.find(':');

                    if (pos != string::npos && token.size() >= 3){
                        string left = token.substr(0, pos);
                        string right = token.substr(pos + 1);

                        try {
                            int indiceInt = stoi(left);
                            int letterInt = stoi(right);

                            unsigned char indice = static_cast<unsigned char>(indiceInt);
                            unsigned char letter = static_cast<unsigned char>(letterInt);

                            indice ^= k;
                            letter ^= k;

                            indice = rotarDerecha(indice, n);
                            letter = rotarDerecha(letter, n);

                            JSON[index] = new char[2];
                            JSON[index][0] = indice;
                            JSON[index][1] = letter;

                            index++;

                        } catch (const std::exception& e) {
                            cout << "Error en token: " << token << " -> " << e.what() << endl;
                        }
                    }

                    token.clear();
                }else token += data[i][f];
            }

            arrayOfJson[i] = JSON;

        }

        // for (short i = 0; i < rows; i++){

        //     for (short c = 0; c < colss[i]; c++){
        //         cout << arrayOfJson[i][c][0] << "  :  " << arrayOfJson[i][c][1];
        //     }
        //     cout << endl;
        // }

      descomLZ78(arrayOfJson, rows, colss);

        if (data != nullptr) delete[] data;

        if (arrayOfJson != nullptr){
            for (short i = 0; i < rows; i++){
                for (short c = 0; c < cols; c++) {
                    if (arrayOfJson[i][c] != nullptr)  delete[] arrayOfJson[i][c];
                }

                if (arrayOfJson[i] != nullptr) delete[] arrayOfJson[i];
            }

            delete[] arrayOfJson;
        }

    }


    if (dataToEncryptRLE != nullptr) delete[]dataToEncryptLZ78;

    if (dataToEncryptLZ78 != nullptr){
        for (short i = 0; i < rows; i++){
            for (short c = 0; c < cols; c++) delete[] dataToEncryptLZ78[i][c];
            delete[] dataToEncryptLZ78[i];
        }

        delete[] dataToEncryptLZ78;
    }

    main();
    return 0;
}

unsigned char rotarIzquierda(unsigned char byte, int n) {
    return (byte << n) | (byte >> (8 - n));
}

unsigned char rotarDerecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}
