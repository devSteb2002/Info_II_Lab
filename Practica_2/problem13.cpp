#include "Problems.h"

using namespace std;

short getNumberOfStarts(short** galaxy, short row = 6, short column = 8);

void Problem13(){

    cout << "==========================" << endl;
    cout << "Problema # 13" << endl;
    cout <<  "==========================" << endl;

    const short consGgalaxyNGC[6][8] = {
        { 0, 3, 4, 0, 0, 0, 6, 8 },
        { 5, 13, 6, 0, 0, 0, 2, 3},
        { 2, 6, 2, 7, 3, 0, 10, 0},
        { 0, 0, 4, 15, 4, 1, 6, 0},
        { 0, 0, 7, 12, 6, 9, 10, 4},
        { 5, 0, 6, 10, 6, 4, 8, 0}
    };

    short** galaxy = new short*[6];

    for (short i = 0; i <6; i++){
        galaxy[i] = new short[8];

        for (short j = 0; j < 8; j++){
            galaxy[i][j] = consGgalaxyNGC[i][j];
        }
    }

    short numberTotal = getNumberOfStarts(galaxy);
    cout << "El numero de estrellas es: " << numberTotal << endl;

    for (short i = 0; i < 6; i++){
        delete[] galaxy[i];
    }

    delete[] galaxy;
}

short getNumberOfStarts(short** galaxy, short row , short column){

    unsigned int countOfStarts = 0;

    for (short i = 0; i < row; i++){
        for (short j = 0; j < column; j++){

            if (i > 0 && i  < (row - 1)){
                if (j > 0 && j < (column - 1)){
                    const float numberOfStarts = galaxy[i][j] + galaxy[i][j - 1] + galaxy[i][j+1] + galaxy[i-1][j] + galaxy[i+1][j];
                    if (numberOfStarts / 5.0  > 6) {
                        countOfStarts += 1;
                        cout << "Estrella encontrada en la posicion (" << i << ", " << j << ") = " << *(*(galaxy +i) + j) << endl;
                    }
                }
            }
        }
    }

    return countOfStarts;
}
