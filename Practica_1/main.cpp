#include <iostream>

using namespace std;


int main()
{

    string  option = "";
    bool    chooseOption = false;

    const string arrayProblems[8] = {
        "Problemas 3",
        "Problemas 5",
        "Problemas 7",
        "Problemas 9",
        "Problemas 11",
        "Problemas 13",
        "Problemas 15",
        "Problemas 17",
};

    cout << "==========================================" << endl;
    cout << " Practica #1                                                 " << endl;
    cout << "==========================================" << endl;

    cout << "Lista de problemas:" << endl;
    for (short i = 0; i < 8; i++) cout << arrayProblems[i] << "  ->  " << " opcion " <<  (i +1) << endl;

    do {

        cout << "Ingrese una opcion: ";
        cin >> option;

        unsigned short    index = 0;
        bool                    areDigits = true;
        bool                    endProblem = false;

        for (char c : option) {
            index++;

            if (c < 48 || c > 57){
                cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                areDigits = false;
                break;
            }
        }

        if (!areDigits) continue;

        if (index > 1){
            cout << "Maximo un digito, vuelva a intentar." << endl;
            continue;
        }

        if (option == "0"){
            cout << "Ingrese un numero diferente de cero, vuelva a intentar." << endl;
            continue;
        }

        if (option == "1"){
            cout << "==========================================" << endl;
            cout << " Problema #3                                               " << endl;
            cout << "==========================================" << endl;

            string                month = "";
            string                day =  "";
            bool                   isValidMonth = false;
            const  short     daysOfMonths[12] = {
                31, 28, 31, 30,
                31, 30, 31, 31,
                30, 31, 30, 31
            };

            do {

                bool    hasLetter = false;
                short   indString = 0;

                if (!isValidMonth){  // primero validamos que el mes sea correcto

                    cout << "Ingrese un mes: ";
                    cin >> month;

                    for (char c : month){
                        indString++;

                        if (c < 48 || c > 57){
                            cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                            hasLetter = true;
                            break;
                        }
                    }

                    if (hasLetter) continue;

                    if (indString > 2){
                        cout << "Maximo dos digitos, vuelva a intentar." << endl;
                        continue;
                    }

                    if (month[0] == '0'){
                        cout << "El digito debe ser diferente de cero, vuelva a intentar." << endl;
                        continue;
                    }

                    if (indString == 2){
                        if ((month[0] -'0') * 1 > 1 || (month[1] - '0') * 1 > 2){
                            cout << month << " es un mes invalido, vuelva a intentar." << endl;
                            continue;
                        }
                    }

                    isValidMonth = true;
                }
                else {   // validamos el dia

                    cout << "Ingrese el dia: ";
                    cin >> day;

                    for (char c : day){
                        indString++;

                        if (c < 48 || c > 57){
                            cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                            hasLetter = true;
                            break;
                        }
                    }

                    if (hasLetter) continue;

                    if (indString > 2){
                        cout << "Maximo dos digitos, vuelva a intentar." << endl;
                        continue;
                    }

                    if (day[0] == '0'){
                        cout << "El digito debe ser diferente de cero, vuelva a intentar." << endl;
                        continue;
                    }

                    if (indString == 2){
                        if (((day[0] - '0') * 1) > 3 ||  (day[0] == '3'  && (day[1] - '0') * 1 > 1) ){
                                cout << day << " es un dia invalido, vuelva a intentar." << endl;
                                continue;
                        }
                    }

                      break;
                }

            } while (true);

            short digitsInMonth = 0;
            short digitsInDay = 0;
            short  intMonth = 0;
            short  intDay = 0;

            for (char c : month) digitsInMonth++;
            for (char c: day) digitsInDay++;

            if (digitsInMonth == 2) intMonth =  (month[0] - '0') * 10  + (month[1] -'0') * 1;
            else intMonth = (month[0] - '0') * 1;

            if (digitsInDay == 2) intDay = (day[0] - '0') * 10 +  (day[1] - '0') * 1;
            else intDay = (day[0] - '0') * 1;

            if (intMonth == 2 && intDay == 29){
                cout << intDay << "/" << intMonth << " es valido en bisiesto." << endl;
            }
            else if (intDay > daysOfMonths[intMonth - 1]){
                cout << intDay << "/" << intMonth << " es una fecha invalida." << endl;
            } else cout <<  intDay  << "/" << intMonth  << " es una fecha valida." << endl;
        }

        //==============================================================
        //==============================================================
        //==============================================================
        else if (option == "2"){
            cout << "==========================================" << endl;
            cout << " Problema #5                                               " << endl;
            cout << "==========================================" << endl;

            string                numberN = "";
            unsigned short  sum = 0;


            do {
                bool    hasletter = false;
                short     indexN = 0;

                cout << "Ingrese un numero entero impar: ";
                cin >> numberN;

                for (char  c : numberN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN > 4 ){
                    cout << "Solo numeros de 1 a 4 digitos, vuelva a intentar." << endl;
                    continue;
                }

                sum = 0;

                for (short i = 0; i < indexN; i++){
                    if (indexN - i == 4) sum = sum +  (numberN[i] - '0') * 1000;
                    else  if (indexN - i == 3) sum = sum +  (numberN[i] - '0') * 100;
                    else  if (indexN - i == 2) sum = sum +  (numberN[i] - '0') * 10;
                    else  if (indexN - i == 1) sum = sum +  (numberN[i] - '0') * 1;
                }

                if ((sum & 1) == 0) {
                    cout << "El numeo " << sum << " no es impar, vuelva a intentar." << endl;
                    continue;
                }

                break;

            }while (true);

            for (unsigned short i = 0; i <= sum; i++){ // abajo arriba
                if ((i & 1) == 1){
                    unsigned short  whiteSpaces = (sum - i) / 2;
                    unsigned short  numChaInLine = sum - (whiteSpaces * 2);

                    for (unsigned short f = 0; f < whiteSpaces; f++) cout << " ";
                    for (unsigned short f = 0; f < numChaInLine; f++) cout << "*";

                    cout << endl;
                }
            }

            for (unsigned short i = sum - 1; i > 0; i--){ //arriba abajo
                if ((i & 1) == 1){
                    unsigned short  whiteSpaces = (sum - i) / 2;
                    unsigned short  numChaInLine = sum - (whiteSpaces * 2);

                    for (unsigned short f = 0; f < whiteSpaces; f++) cout << " ";
                    for (unsigned short f = 0; f < numChaInLine; f++) cout << "*";

                    cout << endl;
                }
            }
        }
        //==============================================================
        //==============================================================
        //==============================================================
        else if (option == "3"){
            cout << "==========================================" << endl;
            cout << " Problema #7                                               " << endl;
            cout << "==========================================" << endl;

            string               numN;
            unsigned short  sum = 0;

            do {
                cout << "Ingrese un numero entero: ";
                cin >> numN;

                bool      hasletter = false;
                short     indexN = 0;

                for (char  c : numN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN > 4 ){
                    cout << "Solo numeros de 1 a 4 digitos, vuelva a intentar." << endl;
                    continue;
                }

                for (short i = 0; i < indexN; i++){
                    if (indexN - i == 4) sum = sum +  (numN[i] - '0') * 1000;
                    else  if (indexN - i == 3) sum = sum +  (numN[i] - '0') * 100;
                    else  if (indexN - i == 2) sum = sum +  (numN[i] - '0') * 10;
                    else  if (indexN - i == 1) sum = sum +  (numN[i] - '0') * 1;
                }

                break;

            }while(true);

            unsigned short  number1 = 1;
            unsigned short  number2 = 1;
            unsigned short  auxNumber;
            unsigned int  sumOfPars = 0;

            for (unsigned  short i = 0; i < sum; i++){
                auxNumber = number1;
                number1 = number1 + number2;
                number2 =    auxNumber;

                if (number1 < sum  && ((number1 & 1) == 0)) sumOfPars += number1;

                if (number1 >= sum) break;
            }

            cout << "El resultado de la suma es: " << sumOfPars << endl;

        }
        else if (option == "4"){
            cout << "==========================================" << endl;
            cout << " Problema #9                                              " << endl;
            cout << "==========================================" << endl;

            string       numN;

            do {
                cout << "Ingrese un numero entero: ";
                cin >> numN;

                bool      hasletter = false;
                short     indexN = 0;

                for (char  c : numN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;


                break;

            }while(true);

            unsigned  short  totalSum = 0;

            for (char c : numN){
                short                number = (c - '0') * 1;
                unsigned int potence = number;

                for (short i = 1; i < number; i++){
                    potence *= number;
                }

                totalSum += potence;
            }

            cout << "El resultado de la suma es: " << totalSum << endl;
        }
        else if (option == "5"){
            cout << "==========================================" << endl;
            cout << " Problema #11                                              " << endl;
            cout << "==========================================" << endl;

            string               numN;
            unsigned short  sum = 0;

            do {
                cout << "Ingrese un numero entero: ";
                cin >> numN;

                bool      hasletter = false;
                short     indexN = 0;

                for (char  c : numN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN > 4 ){
                    cout << "Solo numeros de 1 a 4 digitos, vuelva a intentar." << endl;
                    continue;
                }

                for (short i = 0; i < indexN; i++){
                    if (indexN - i == 4) sum = sum +  (numN[i] - '0') * 1000;
                    else  if (indexN - i == 3) sum = sum +  (numN[i] - '0') * 100;
                    else  if (indexN - i == 2) sum = sum +  (numN[i] - '0') * 10;
                    else  if (indexN - i == 1) sum = sum +  (numN[i] - '0') * 1;
                }

                break;

            }while(true);

            //MCM(a, b) = |a x b| / MCD(a, b)

            unsigned int  result = 1;

            for (unsigned short i = 1; i <= sum; i++){
                unsigned int nextN = i + 1;

                if (nextN < (sum + 1)){

                   unsigned int  b = nextN;
                   unsigned int   a = result;

                    while (b != 0){ // algoritmo de euclides
                        unsigned int temp = b;
                        b = a % b;
                        a = temp;
                    }

                    result = (result * nextN) / a;

                }
            }

            cout <<  "El minimo comun multiplo es: " << result << endl;

        }
        else if (option == "6"){
            cout << "==========================================" << endl;
            cout << " Problema #13                                              " << endl;
            cout << "==========================================" << endl;

            string               numN;
            unsigned int  sum = 0;

            do {
                cout << "Ingrese un numero entero: ";
                cin >> numN;

                bool      hasletter = false;
                short     indexN = 0;

                for (char  c : numN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN > 5 ){
                    cout << "Solo numeros de 1 a 5 digitos, vuelva a intentar." << endl;
                    continue;
                }

                for (short i = 0; i < indexN; i++){
                     if (indexN - i == 5) sum = sum +  (numN[i] - '0') * 10000;
                    else if (indexN - i == 4) sum = sum +  (numN[i] - '0') * 1000;
                    else  if (indexN - i == 3) sum = sum +  (numN[i] - '0') * 100;
                    else  if (indexN - i == 2) sum = sum +  (numN[i] - '0') * 10;
                    else  if (indexN - i == 1) sum = sum +  (numN[i] - '0') * 1;
                }

                break;

            }while(true);

            unsigned int sumPrimes = 0;

            for (unsigned int  i = 2; i < sum; i++){

                short numberOfDividers = 0;

                if (i == 2){
                    sumPrimes += i;
                    continue;
                }

                for (unsigned int f = 1; f <= i; f++){

                    if (i % f == 0 && (i & 1) == 1){
                        numberOfDividers ++;
                    }
                }

                if (numberOfDividers == 2) sumPrimes += i;
            }

            cout << "El resultado de la suma es: " << sumPrimes << endl;
        }
        else if (option == "7"){
            cout << "==========================================" << endl;
            cout << " Problema #15                                              " << endl;
            cout << "==========================================" << endl;

            string                numberN = "";
            unsigned int  sum = 0;


            do {
                bool    hasletter = false;
                short     indexN = 0;

                cout << "Ingrese un numero entero impar: ";
                cin >> numberN;

                for (char  c : numberN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN > 4 ){
                    cout << "Solo numeros de 1 a 4 digitos, vuelva a intentar." << endl;
                    continue;
                }

                sum = 0;

                for (short i = 0; i < indexN; i++){
                    if (indexN - i == 4) sum = sum +  (numberN[i] - '0') * 1000;
                    else  if (indexN - i == 3) sum = sum +  (numberN[i] - '0') * 100;
                    else  if (indexN - i == 2) sum = sum +  (numberN[i] - '0') * 10;
                    else  if (indexN - i == 1) sum = sum +  (numberN[i] - '0') * 1;
                }

                if ((sum & 1) == 0) {
                    cout << "El numeo " << sum << " no es impar, vuelva a intentar." << endl;
                    continue;
                }

                break;
            }while (true);

            unsigned int        n = sum * sum;
            unsigned int        array[sum][sum];
            unsigned short    row = 0;
            unsigned short    col = 0;
            unsigned short    rowEnd = sum;
            unsigned short    colEnd = sum;

            while (n > 0){

                //fila  arriba
                for ( int i = colEnd -1; i >= col; i--){
                    array[row][i] = n;
                    n--;
                }

                row++;

                //columna izquierda
                for (int i = row; i < rowEnd; i++){
                    array[i][col] = n;
                    n--;
                }
                col++;

                //fila abajo
                for (int i = col; i < colEnd; i++){
                    array[rowEnd - 1][i] = n;
                    n--;
                }

                rowEnd--;

                //columna derecha
                for (int i = rowEnd - 1; i >= row; i--){
                    array[i][colEnd - 1] = n;
                    n--;
                }

                colEnd--;
            }

            unsigned int   indDiaRigth = 0, indDiaLeft = sum - 1;
            unsigned int   sumDiagonals = 0;

            //calcular valores de la diagonla
            for (int i = 0; i < sum; i++){

                unsigned const int  position1 = array[i][indDiaRigth];
                unsigned const int  position2 = array[i][indDiaLeft];

                if (position1 == position2) sumDiagonals += position1;
                else sumDiagonals += position1 + position2;

                indDiaRigth++;
                indDiaLeft--;
            }


            for (int i = 0 ; i < sum; i++){
                for (int f = 0 ;  f < sum; f++) cout << array[i][f] << "  ";
                cout << endl << endl;
            }

            cout << "En una espiral de " << sum << "x" << sum <<", la suma es: " << sumDiagonals << endl;

        }
        else if (option == "8"){
            cout << "==========================================" << endl;
            cout << " Problema #17                                              " << endl;
            cout << "==========================================" << endl;

            string               numN;
            unsigned int     sum = 0;

            do {
                cout << "Ingrese un numero entero: ";
                cin >> numN;

                bool      hasletter = false;
                short     indexN = 0;

                for (char  c : numN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN > 5 ){
                    cout << "Solo numeros de 1 a 5 digitos, vuelva a intentar." << endl;
                    continue;
                }

                for (short i = 0; i < indexN; i++){
                    if (indexN - i == 5) sum = sum +  (numN[i] - '0') * 10000;
                    else if (indexN - i == 4) sum = sum +  (numN[i] - '0') * 1000;
                    else  if (indexN - i == 3) sum = sum +  (numN[i] - '0') * 100;
                    else  if (indexN - i == 2) sum = sum +  (numN[i] - '0') * 10;
                    else  if (indexN - i == 1) sum = sum +  (numN[i] - '0') * 1;
                }

                break;

            }while(true);


            unsigned int  numberInPosition, numOfDivider = 0;
            unsigned int  n = 1;

            do {
                numberInPosition = n * (n + 1) / 2;

                int count = 0;;
                for (int i = 1; i <= numberInPosition; i++){
                    if (numberInPosition % i == 0) count++;
                }
                numOfDivider = count;


                if (numOfDivider > sum) break;

                n++;

            } while (true);

            cout << "El numero es: " << numberInPosition  << " que tiene "  << numOfDivider << " divisores." << endl;

        }

    } while (true);

    return 0;
}

