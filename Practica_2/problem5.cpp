#include "Problems.h"

using namespace std;

int askNumberEnter();
void transformInt(int number, string &numberInString);

void problem5(){

    cout << "==========================" << endl;
    cout << "Problema # 5" << endl;
    cout <<  "==========================" << endl;

    int number = askNumberEnter();
    string numberInString;

    transformInt(number, numberInString);

    cout << "La cadena es: " << numberInString << endl;
}

void transformInt(int number, string &numberInString){
    numberInString = to_string(number);
}

int askNumberEnter(){

    int number;

    while(true){
        cout << "Ingrese un numero entero: ";
        cin >> number;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Numero invalido, intente otra vez." << endl;
            continue;
        }

        return number;
    }
}
