#include "Ejercicios.h"

using namespace std;


/*Ejercicio 10. Escriba un programa que pida un número N e imprima en pantalla todos los múltiplos de dicho número entre 1 y 100.
    Ej: si se ingresa 33 se debe imprimir:
    Multiplos de 33 menores que 100:
     33
    66
     99 */

void ejercicio10(){

    string    input;
    bool      hasletters;
    bool      isMajorThanZero;
    int        numberN;

    do {

        hasletters = false;
        isMajorThanZero = false;

        cout << "Ingrese un numero N entero positivo: ";
        cin >> input;

        for (short i = 0; i < input.size(); i++){

            if (i == 0 && input[i] == '-'){
                cout << "El numero debe ser positivo, vuelva a intentar." << endl;
                isMajorThanZero = true;
                continue;
            }

            if (!isdigit(input[i])){
                cout << "Tipo de dato no valido, vuelva a intentar." << endl;
                hasletters = true;
                break;
            }
        }

        if (!hasletters && !isMajorThanZero){
            if (stoi(input) == 0){
                cout << "El numero debe ser mayor que cero, vuelva a intentar." << endl;
            }
            else break;
        }

    } while(true);

    numberN = stoi(input);

    cout << "Multiplos de " <<  numberN << ":" << endl;

    for (short i = 1; i <= 100; i++){
        if ((numberN * i) <= 100) cout << (numberN * i) << endl;
    }
}
