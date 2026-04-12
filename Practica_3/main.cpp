#include "Definition.h"

using namespace std;

int main()
{
    cout << "=======================" <<  endl;
    cout << "Practica # 3 " << endl;
    cout << "=======================" <<  endl;

    string option = "";

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

    string *dataToEncryptRLE = nullptr;
    string ***dataToEncryptLZ78 = nullptr;
    int rows;

    if (option == "1"){
        dataToEncryptRLE = initRLE(rows);
    } else {
        dataToEncryptLZ78 = initLZ78(rows, "encrypt");
    }

    cout << "hola";
    /*for (int i = 0; i < rows; i++){
        cout << dataToEncryptRLE[i] <<  " --- " << endl;
    }


    delete[] dataToEncryptRLE; */

    return 0;
}
