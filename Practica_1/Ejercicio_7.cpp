#include "Ejercicios.h"

using namespace std;

/*Ejercicio 7. Escriba un programa que pida un número N e imprima en pantalla la suma de todos
 los números entre 0 y N (incluyéndose el mismo).
 Ej: si se ingresa 5: 1+2+3+4+5=15, por lo que se debe imprimir:
La sumatoria desde 0 hasta 5 es: 15 */


void ejercicio7(){

    int        numberN;
    bool      isPositiveN = true;
    string    input;
    int        sum = 0;

    do {

       bool      hasLetters = false;

        cout << "Ingrese el numero entero N: ";
        cin >> input;

        for (short i = 0; i < input.size(); i++){

            if (i == 0 && input[0] == '-') continue;

            if (!isdigit(input[i])){
                cout << "Tipo de dato invalido, vuelva a intentar." << endl;
                hasLetters = true;
                break;
            }
        }

        if (!hasLetters)  break;

    } while (true);

    numberN = stoi(input);

    if (numberN < 0)   isPositiveN = false;

    numberN = numberN < 0 ? numberN*(-1) : numberN;

    for (short i = 1; i <= numberN; i++) sum += i;

    if (!isPositiveN) {
        numberN = numberN * (-1);
        sum = sum * (-1);
    }

    cout << "La sumatoria desde 0 hasta " << numberN << " es: " << sum << endl;

}
