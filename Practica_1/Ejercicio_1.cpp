#include "Ejercicios.h"
#include <cmath>
#include <limits>


//Ejercicio 1. Escriba un programa que pida dos números A y B e imprima en pantalla el residuo
//  de la división A/B.
   /*   Ej: si se ingresan 8 y 3 se debe imprimir:
     El residuo de la division 8/3 es: 2
    Nota: Nótese que la palabra división no tiene tílde, esto no es un error tipográco, es debido a que
    no se puede imprimir correctamente tíldes en la terminal. De ahora en adelante todos los ejemplos
    de salidas contendrán el mismo error tipográco. */

using namespace std;


void ejercicio1(){

    float    numberA;
    float    numberB;
    bool    stateFirtsNumber = false;


    do {

        if (!stateFirtsNumber) {

            cout << "Ingrese el primer numero: ";
            cin >> numberA;

            if (!validateInput()) continue;

            stateFirtsNumber = true;

        }
        else {

            cout << "Ingrese el segundo numero: ";
            cin >> numberB;

            if (!validateInput()) continue;

            if (numberB == 0) {
                cout << "El denomindaor no puede ser cero, vuelva a intentar." << endl;
                continue;
            }

            break;
        }
    } while (true);


    float    result = fmod(numberA, numberB);
    cout << "El residuo de la division " << numberA << "/" << numberB << " es: " << result << endl;

}
