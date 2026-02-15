#include "Ejercicios.h"

using namespace std;


/*Ejercicio 4. Escriba un programa que pida dos números A y B e imprima en pantalla el menor.
 Ej: si se ingresan 7 y 3 se debe imprimir:
El menor es 3 */

void Ejercicio4(){

    float    numberA;
    float    numberB;
    bool    isValidNumberA = false;


    do {
        if (!isValidNumberA){
            cout << "Ingrese el numero A: ";
            cin >> numberA;

            if (!validateInput()) continue;

            isValidNumberA = true;
        }
        else {
            cout << "Ingrese el numero B: ";
            cin >> numberB;

            if (!validateInput()) continue;

            break;
        }

    } while(true);

    if (numberA < numberB) cout << "El menor es " << numberA << endl;
    else if (numberB < numberA) cout << "El menor es " << numberB << endl;
    else cout << "Ambos son iguales." << endl;

}
