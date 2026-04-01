#include "Problems.h"

using namespace std;

void clearCin();

int main()
{
    short option;
    const string options[11] = {
        "Problema  # 1",
        "Problema  # 3",
        "Problema  # 5",
        "Problema  # 6",
        "Problema  # 7",
        "Problema  # 9",
        "Problema  # 10",
        "Problema  # 11",
        "Problema  # 13",
        "Problema  # 15",
        "Problema  # 17"
    };

    cout << "======================" << endl;
    cout << "Practica # 2" << endl;
    cout << "======================" << endl;

    for (short i = 0; i < 11; i++)  cout << options[i] << ", opcion " << (i + 1) << endl;

    do {
        cout << "Seleccione una opcion: ";
        cin >> option;

        if (cin.fail()){
            clearCin();
            cout << "Tipo de dato invalido, vuelva a intentar." << endl;
            continue;
        }

        if (option < 1 | option > 11){
            clearCin();
            cout << "Solo se permiten valores entre 1 y 11" << endl;
            continue;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max() , '\n');

        if (option == 1) Problem1();
        else if (option == 2)  Problem3();
        else if (option == 3)  problem5();
        else if (option == 4)  Problem6();
        else if (option == 5) problem7();
        else if (option == 6) Problem9();
        else if (option == 7) Problem10();
        else if (option == 8) Problem11();
        else if (option == 9) Problem13();

    } while (true);


    return 0;
}


void clearCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
