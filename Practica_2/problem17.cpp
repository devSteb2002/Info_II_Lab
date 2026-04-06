#include "Problems.h"

using namespace std;

void askNumber(int &number);
int sumDividers(const int& number);
void addElementInArray(int *& array, int rows, int number);

void Problem17(){
    cout << "==========================" << endl;
    cout << "Problema # 17" << endl;
    cout <<  "==========================" << endl;

    int number;
    int sum = 0;
    int * array = nullptr;
    int row = 0;

    askNumber(number);

    for (short i = 1; i <= number; i++){
        int result = sumDividers(i);

        if (result != 0){
            addElementInArray(array, row, result);
            row++;
        }
    }

    for (int i = 0; i < row; i++){
        sum += array[i];
       for (int f = i + 1; f < row; f++) if (array[f] == array[i])  array[f] = 0;
    }

    cout << "El resultado de la suma es: " << sum  << endl;


    delete[] array;
}

void addElementInArray(int *& array, int rows, int number){
    int * newArray = new int[rows + 1];

    for (int i = 0; i < rows; i++){
        newArray[i] = array[i];
    }
    newArray[rows] = number;

    delete[] array;
    array = newArray;
}


int sumDividers(const int& number){

    int sum = 0;
    int secondSum = 0;

    for (short i = 1; i < number; i++) if (number % i == 0) sum += i;
    for (short i = 1; i < sum; i++) if (sum % i == 0) secondSum += i;

    if (secondSum == number && sum != secondSum){ // es amigable
        return  sum + secondSum;
    }

    return 0;

}


void askNumber(int &number){

    do {
        cout << "Ingrese un numero entero: ";
        cin >> number;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Tipo de dato invalido, vuelva a intentar." << endl;
            continue;
        }

        break;

    } while (true);

}
