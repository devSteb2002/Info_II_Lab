#include "Ejercicios.h"

using namespace std;

/*Ejercicio 8. Escriba un programa que pida un número N e imprima en pantalla su factorial.
    Ej: si se ingresa 5: 5!=1*2*3*4*5=120, por lo que se debe imprimir:
                                  5!=120
*/

void ejercicio8(){
    string   numberN;
    short    convertNumberN;
    float      factorial = 1.0;

    do {

       bool    hasLetters = false;

        cout << "Ingrese un numero N positivo: ";
        cin >> numberN;

        for (short i = 0; i < numberN.size(); i++){

            if (numberN[i] == '+') continue;

            if (i == 0 && numberN[i] == '-'){
                cout << "Ingrese solo enteros positivos, vuelva a intentar." << endl;
                hasLetters = true;
                break;
            }

            if (!isdigit(numberN[i])){
                cout << "Tipo de dato invalido, vuelva a intentar." << endl;
                hasLetters = true;
                break;
            }
        }

        if (!hasLetters) break;

    } while (true);

    convertNumberN = stoi(numberN);

    for (short i = 1; i <= convertNumberN; i++) factorial = factorial * i;

    cout << numberN << "!" << "=" << factorial << endl;

}
