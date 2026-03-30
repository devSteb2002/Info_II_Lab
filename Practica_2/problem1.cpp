#include "Problems.h"

//arduino https://www.tinkercad.com/things/dvUGaPv0n3F-cambio-de-dinero-problema-1

using namespace std;

bool isNumber(const string& number);

void Problem1(){

    cout << "==========================" << endl;
    cout << "Problema # 1" << endl;
    cout <<  "==========================" << endl;

    string input;
    const int cash[10] = {
        50000, 20000, 10000, 5000,
        2000, 1000, 500, 200, 100, 50
    };

    do {
        cout << "Ingrese el dinero: " ;
        cin >> input;

        if (!isNumber(input)){
            cout << "Se debe ingresar un numero entero, vuelva a intentar." << endl;
            continue;
        }
        break;
    } while (true);

    int money = stoi(input);
    int value = 0;

    for (short i = 0; i < 10; i++){
        const int div = money / cash[i];
        money  = money - (cash[i] * div);
        cout << cash[i] << " " << div << endl;
    }

    cout << "Faltante: " << money << endl;
}

bool isNumber(const string& number){
    return !number.empty() && all_of(number.begin(), number.end(), ::isdigit);
}
