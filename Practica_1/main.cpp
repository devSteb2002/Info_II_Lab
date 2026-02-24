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
        getline(cin, option);

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

           /* Problema 3. Escriba un programa que debe leer un mes y un día de dicho mes para luego decir
                si esa combinación de mes y día son válidos. El caso más especial es el 29 de febrero, en dicho caso
                        imprimir posiblemente año bisiesto.
                    Nota: el formato de salida debe ser:
                                                           14 es un mes invalido.
                                                           31/4 es una fecha invalida.
                      27/4 es una fecha valida.
                                                   29/2 es valida en bisiesto. */

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
                    getline(cin, month);

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
                    getline(cin, day);

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
                getline(cin, numberN);

                for (char  c : numberN){
                    indexN++;

                    if (c < 48 || c > 57){
                        cout << "Solo se permiten numeros, vuelva a intentar." << endl;
                        hasletter = true;
                        break;
                    }
                }

                if (hasletter) continue;

                if (indexN >= 4 ){
                    cout << "Solo numeros de 1 a 3 digitos, vuelva a intentar." << endl;
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
                getline(cin, numN);

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

                if (indexN >= 4 ){
                    cout << "Solo numeros de 1 a 3 digitos, vuelva a intentar." << endl;
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
            unsigned short  sumOfPars = 0;

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


        }
    } while (true);

    return 0;
}

