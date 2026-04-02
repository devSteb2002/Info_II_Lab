#include "Problems.h"

using namespace std;

void askInput(int* rectA_, int* rectB_);
bool verifyInput();
int* interceptionBetRects(int* rectA_, int* rectB_ );

void Problem15(){

    cout << "==========================" << endl;
    cout << "Problema # 15" << endl;
    cout <<  "==========================" << endl;

    int* rectA = new int[4];
    int* rectB = new int[4];

    askInput(rectA, rectB);

    int* coordinates = interceptionBetRects(rectA, rectB);

    if (coordinates == nullptr){
        cout << "No existe interseccion entre los rectangulos." << endl;
        return;
    }

    cout << "Rectangulo A: {" << rectA[0] << ", " << rectA[1] << ", " << rectA[2] << ", " << rectA[3] << "}" << endl;
    cout << "Rectangulo B: {" << rectB[0] << ", " << rectB[1] << ", " << rectB[2] << ", " << rectB[3] << "}" << endl;
    cout << "Interseccion C: {" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ", " << coordinates[3] << "}" << endl;

    delete[] rectA;
    delete[] rectB;
    delete[] coordinates;

}

void askInput(int* rectA_, int* rectB_){

    bool coordinateXValid = false, widthValid = false, isCoordinates = false;
    int coordinateX, coordinateY, high, width;

    char whatRect[2] = {'A', 'B'};
    unsigned short contRect = 0;

    do{
        if (!isCoordinates){ // pedir coordenadas
            if (!coordinateXValid){ // pedir coordenada x
                cout << "Ingrese la coordenada x del rectangulo " << whatRect[contRect] << endl;
                cin >> coordinateX;

                if (!verifyInput()) continue;

                coordinateXValid = true;
                continue;
            }
            else{ // pedir cooredada y
                cout << "Ingrese la coordenada y del rectangulo " << whatRect[contRect] << endl;
                cin >> coordinateY;

                if (!verifyInput()) continue;

                isCoordinates = true;
                continue;
            }
        }else{ // pedir dimensiones del rectangulo (alto y ancho)
            if (!widthValid){ // pedir el alto del rectangulo
                cout << "Ingrese el ancho del rectangulo " << whatRect[contRect] << endl;
                cin >> width;

                if (!verifyInput()) continue;

                widthValid = true;
                continue;
            }else{ // pedir ancho del rectangulo
                cout << "Ingrese el alto del rectangulo " << whatRect[contRect] << endl;
                cin >> high;

                if (!verifyInput()) continue;

            }
        }

        contRect++;

        if (contRect == 1){ //Datos del rectangulo A
            rectA_[0] = coordinateX;
            rectA_[1] = coordinateY;
            rectA_[2] = width;
            rectA_[3] = high;

            isCoordinates = false;
            coordinateXValid = false;
            widthValid = false;
        }
        else{ // datos del rectangulo B
            rectB_[0] = coordinateX;
            rectB_[1] = coordinateY;
            rectB_[2] = width;
            rectB_[3] = high;

            break;
        }

    }while(true);
}

int* interceptionBetRects(int* rectA_, int* rectB_ ){

    int* intercepts = new int[4];

    short widthRectA = rectA_[0] + rectA_[2];
    short heigthRectA = rectA_[1] + rectA_[3];

    short widthRectB = rectB_[0] + rectB_[2];
    short heigthRectB = rectB_[1] + rectB_[3];

    if (  //colison en x
        (rectB_[0] > rectA_[0] && widthRectA > widthRectB) ||
        (rectB_[0] < rectA_[0] && widthRectA < widthRectB) ||
        (rectB_[0] > rectA_[0] && widthRectA < widthRectB && rectB_[0] < widthRectA) ||
        (rectB_[0] < rectA_[0] && widthRectA > widthRectB && rectA_[0] < widthRectB)
        ){

        if ( //coliones en y
            (rectB_[1] > rectA_[1] && heigthRectA > heigthRectB) ||
            (rectB_[1] < rectA_[1] && heigthRectA < heigthRectB) ||
            (rectB_[1] > rectA_[1] && heigthRectA < heigthRectB && rectB_[1] < heigthRectA) ||
            (rectB_[1] < rectA_[1] && heigthRectA > heigthRectB && rectA_[1] < heigthRectB)
            ){

            short x, y, widht, height;

            if (rectA_[0] < rectB_[0]){
                x = rectB_[0];
                y = rectB_[1];

                widht = widthRectA - x;
                height = heigthRectA  - y;
            }
            else {
                x = rectA_[0];
                y = rectB_[0];

                widht = widthRectB - x;
                height = heigthRectB - y;
            }

            intercepts[0] = x;
            intercepts[1] = y;
            intercepts[2] = widht;
            intercepts[3] = height;
        }

    }

    return intercepts;

}




bool verifyInput(){ //verficar que la entrada sea correcta
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Dato ingresado no es valido, vuelve a intenar." << endl;
        return false;
    }

    return true;
}
