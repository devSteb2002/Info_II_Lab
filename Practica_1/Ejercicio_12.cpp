#include "Ejercicios.h"

using namespace std;


/*Ejercicio 12. Escriba un programa que pida un número N e imprima todas las potencias desde N1
    hasta N5 .
    Ej: si se ingresa 3 se debe imprimir:
    3∧1=3
    3∧2=9
    3∧3=27
    3∧4=81
    3∧5=243
*/

void  ejercicio12(){
    float    numberN;

    do {
        cout << "Ingrese un numero N: ";
        cin >> numberN;

        if (!validateInput()) continue;

        if (numberN == 0.0){
            cout << "El numero N debe ser diferente de cero, vuelva a intentar." << endl;
            continue;
        }

        if (numberN < 0.0){
            cout << "El numero N debe ser positivo, vuelva a intentar." << endl;
            continue;
        }

        break;

    } while(true);

    cout << numberN;

}
