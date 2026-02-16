#include "Ejercicios.h"

using namespace std;

/*Ejercicio 9. Escriba un programa que pida un número N e imprima el perímetro y área de un
    círculo con radio N. Nota: use 3.1416 como una aproximación de pi.
                               Ej: si se ingresa 1 se debe imprimir:
                                                                       Perimetro: 6.28352
                                                                       Area: 3.1416
*/

void ejercicio9(){

    const float    PI = 3.1416;
    float              perimeter;
    float              area;
    float              radio;


    do {
        cout << "Ingrese un numero N positivo mayor que 0: ";
        cin >> radio;


        if (!validateInput()) continue;

        if (radio <= 0){
            cout << "El numero debe ser positivo mayor que 0, vuelva a intentar." << endl;
            continue;
        }

        break;

    } while (true);

    area = PI * radio * radio;
    perimeter = 2 * radio * PI;

    cout << "Perimetro: " << perimeter << endl;
    cout << "Area: " << area << endl;


}
