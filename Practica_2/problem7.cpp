#include "Problems.h"

using namespace std;

void problem7(){
    cout << "==========================" << endl;
    cout << "Problema # 7" << endl;
    cout <<  "==========================" << endl;

    string chain = "";
    string noRepets = "";


    cout << "Ingrese una cadena: ";
    getline(cin, chain);

    const short lenghtString = chain.length();

    for (short i = 0; i < lenghtString; i++){
        const char item = chain[i];

        if (noRepets.length() == 0) noRepets += item;

        bool findRepeat = false;

        for (short f =0; f < noRepets.length(); f++){
            if (item == noRepets[f]){
                findRepeat = true;
                break;
            }
        }

        if (!findRepeat) noRepets += item;

    }

    cout << "Original: " << chain << ". Sin repetidos: " << noRepets << endl;

}
