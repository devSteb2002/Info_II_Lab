#include "Ejercicios.h"
#include <cmath>

using namespace std;

/*Ejercicio 5. Escriba un programa que pida dos números A y B e imprima en pantalla la división
A/B con redondeo.
 Ej: si se ingresan 8 y 3 se debe imprimir: 8/3=3
Si se ingresan 7 y 3 se debe imprimir:7/3=2 */


void ejercicio5(){

    float    numberA;
    float    numberB;
    float    operation;
    bool    isValidNumberA = false;

    do {

        if (!isValidNumberA){
            cout << "Ingrese el numero A: ";
            cin >> numberA;

            if (!validateInput()) continue;

            isValidNumberA = true;
        }
        else{
            cout << "Ingrese el numero B: ";
            cin >> numberB;


            if (!validateInput()) continue;

            if (numberB == 0){
                cout << "El denominador debe ser diferente de cero, vuelva a intentar." << endl;
                continue;
            }

            break;
        }
    } while (true);

    operation = round(numberA / numberB);

    cout << numberA << "/" << numberB << " = " << operation << endl;
}
