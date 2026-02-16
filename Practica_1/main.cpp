#include "Ejercicios.h"
#include <limits>

using namespace std;


int main()
{
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    //Ejercicio4();
    //ejercicio5();
    //ejercicio6();
    //ejercicio7();
    //ejercicio8();
    //ejercicio9();
    //ejercicio10();
    //ejercicio11();
     ejercicio12();

    return 0;
}


bool validateInput(){
    if (cin.fail()){
        cout << "Tipo de dato invalido, vuelva a intentar." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return false;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}
