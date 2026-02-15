#include "Ejercicios.h"

/*Ejercicio 2. Escriba un programa que pida un número N e imprima en pantalla si es par o impar.
 Ej: si se ingresa 5 se debe imprimir:
5 es impar */

using namespace std;

void ejercicio2(){

    string    input = "";
    int         number;


    do {
        cout << "Ingrese un numero entero: ";
        cin >> input;

        bool   isFloat = false;
        bool   hasLetters = false;


        for (short i = 0; i < input.size(); i++ ){
            if (input[i] == '.' || input[i] == ','){
                cout << "El numero debe ser entero, vuelva a intentar. " << endl;
                isFloat = true;
                break;
            }

            if (!isdigit(input[i])) {
                cout << "No se permiten letras, vuelva a intentar. " << endl;
                hasLetters = true;
                break;
            }
        }


        if (!isFloat && !hasLetters)  break;

    } while (true);

    number = stoi(input);

    if ((number & 1) == 0){
        cout << "El numero es par." << endl;
    }
    else {
        cout << "El numero es impar" << endl;
    }

}
