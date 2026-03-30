#include "Problems.h"

using namespace std;

bool compare(const string& first, const string& second);

void Problem3(){
    cout << "==========================" << endl;
    cout << "Problema # 3" << endl;
    cout <<  "==========================" << endl;

    string  firstString = "";
    string  secondString = "";

    cout << "Ingrese la primera cadena: ";
    getline(cin, firstString);

    cout << "Ingrese la segunda cadena: ";
    getline(cin, secondString);

    bool result = compare(firstString, secondString);

    if (result) cout << "Verdadero" << endl;
    else cout << "Falso" << endl;
}

bool compare(const string& first, const string& second){
    return (first.length() == second.length()) && (first == second);
}
