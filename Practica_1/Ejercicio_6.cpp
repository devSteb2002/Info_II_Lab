#include "Ejercicios.h"

using namespace std;
/*Ejercicio 6. Escriba un programa que pida dos números A y B e imprima en pantalla la potencia
 AB, sin hacer uso de librerías matemáticas.
Ej: si se ingresan 5 y 3 se debe imprimir:5∧3=125 */

void ejercicio6(){
    float     numberA;
    float     operation = 1.0;
    string   potence;
    bool     isValidNumberA = false;
    int       numberB;

    do {

        bool     isFloat = false;
        bool     hasLetter = false;

        if (!isValidNumberA){
            cout << "Ingrese el numero A: ";
            cin >> numberA;

            if (!validateInput()) continue;

            isValidNumberA = true;
        }
        else{
            cout << "Ingrese el numero B: ";
            cin >> potence;

            for (short i = 0; i < potence.size(); i++){

                if (i == 0 && potence[0] == '-') continue;

                if (potence[i] == '.' || potence[i] == ','){
                    cout << "Tipo de dato invalido, vuelva a intentar." << endl;
                    isFloat = true;
                    break;
                }

                if (!isdigit(potence[i])){
                    cout << "Tipo de dato invalido, vuelva a  intentar." << endl;
                    hasLetter = true;
                    break;
                }
            }

            if (!isFloat && !hasLetter) break;
        }

    } while (true);

    numberB = stoi(potence);

    if (numberB < 0){
        for (short i = -1; i >= numberB; i--)  operation = operation * (1/numberA);
    }
    else if (numberB > 0){
        for (short i = 1; i <= numberB; i++) operation = operation * numberA;
    }
    else operation =  1;

    cout << numberA << "^" << numberB << "=" << operation << endl;

}
