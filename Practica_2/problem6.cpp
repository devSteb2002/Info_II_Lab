#include "Problems.h"

using namespace std;

// https://www.tinkercad.com/things/k9xAQzsehQa-problema-6

void Problem6(){
    cout << "==========================" << endl;
    cout << "Problema # 6" << endl;
    cout <<  "==========================" << endl;

    string chain = "";
    string original = "";

    cout << "Ingrese la cadena: ";
    getline(cin, chain);

    original = chain;

    for (char &c: chain){
        if (!isdigit(c)){
            c = ::toupper(c);
        }
    }

    cout << "Original : " << original << ". En mayuscula: " << chain << endl;

}
