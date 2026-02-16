#include "Ejercicios.h"

using namespace std;

/*Ejercicio 11. Escriba un programa que pida un número N e imprima en pantalla su tabla de multiplicar hasta 10xN.
    Ej: si se ingresa 7 se debe imprimir:
                                            1x7=7
                                            2
                                            2x7=14
                                            3x7=21*/

void ejercicio11(){
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

        if (!hasletters && !isMajorThanZero) {
            if (stoi(input) == 0){
                cout << "El numero debe ser mayor que cero, vuelva a intentar." << endl;
            }
            else break;
        }

    } while(true);

    numberN = stoi(input);

    for (short i = 1; i <= 10; i++){
        int   multiplication = i * numberN;
        cout << i << "x" << numberN << "=" << multiplication << endl;
    }

}
