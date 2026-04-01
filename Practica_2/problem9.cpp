#include "Problems.h"

using namespace std;

int askN();
string askChain();

void Problem9(){
    cout << "==========================" << endl;
    cout << "Problema # 9" << endl;
    cout <<  "==========================" << endl;

    const int n = askN();
    string chain = askChain();
    const string original = chain;

    while (true){
        if (chain.length() % n != 0) chain = '0' + chain;
        else break;
    }

    short  times = chain.length() / n;
    short indexToIterar = 0;
    int   totalSum = 0;

    for (short i = 0; i < times; i++){
        string dividers = "";

        for (short f = indexToIterar; f < (indexToIterar + times); f++) dividers += chain[f];

        totalSum += stoi(dividers);
        indexToIterar += times;
    }

    cout << "Original: " << original << endl;
    cout << "Suma: " << totalSum << endl;
}

int askN(){
    string n;

    do {
        cout << "Ingrese el numero n: ";
        getline(cin, n);

        if (!all_of(n.begin(), n.end(), ::isdigit)){
            cout << "Solo se permiten numero enteros, vuelva a intentar." << endl;
            continue;
        }

        break;

    }while(true);

    return stoi(n);
}

string askChain(){
    string chain;

    do {
        cout << "Ingrese una cadena de numeros: ";
        getline(cin, chain);

        if (!all_of(chain.begin(), chain.end(), ::isdigit)){
            cout << "Solo se permite cadena enteros, vuelva a intentar." << endl;
            continue;
        }

        break;
    } while (true);

    return chain;
}
