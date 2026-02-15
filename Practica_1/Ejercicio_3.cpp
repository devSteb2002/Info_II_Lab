#include "Ejercicios.h"

/*Ejercicio 3. Escriba un programa que pida dos números A y B e imprima en pantalla el mayor.
    Ej: si se ingresan 7 y 3 se debe imprimir:
    El mayor es 7 */

using namespace std;

void ejercicio3(){

    float   numberA;
    float   numberB;
    bool    isValidFirtNumber = false;

    do {

        if (!isValidFirtNumber){
            cout << "Ingrese el primer numero: ";
            cin >> numberA;

            if (!validateInput()) continue;

            isValidFirtNumber = true;
        }
        else {
            cout << "Ingrese el segundo numero: ";
            cin >> numberB;

            if (!validateInput()) continue;

            break;
        }

    } while (true);

    if (numberA > numberB) cout << "El mayor es " << numberA << endl;
    else if (numberB > numberA) cout << "El mayor es " << numberB << endl;
    else cout << "Ambos son iguales" << endl;

}
