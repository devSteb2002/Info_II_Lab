#include "Problems.h"

// https://www.tinkercad.com/things/6Z9PcGRSYrw-problema-10

using namespace std;

string askNumberInRoman(const string &RomanCharacters);
short getValueLetter(const char& letter);

void Problem10(){
    cout << "==========================" << endl;
    cout << "Problema # 10" << endl;
    cout <<  "==========================" << endl;

    const string RomanCharacters = "MDCLXVI";
    int  sum = 0;

    string romanNumber = askNumberInRoman(RomanCharacters);


    for (short i = 0; i < romanNumber.length(); i++){
        char actual = romanNumber[i];
        char next = ((i + 1) < romanNumber.length()) ? romanNumber[i + 1] : 'N';
        short nActual = getValueLetter(actual);
        short nNext    = getValueLetter(next);

        if (nActual < nNext && next != 'N') {
            sum += nNext - nActual;
            i += 1;
        }
        else if (nActual >=nNext && next != 'N'){
            sum += nActual;
        }
        else if (next == 'N'){
            sum += nActual;
        }
    }

    cout << "El numero ingresado fue: " << romanNumber << endl;
    cout << "Que corresponde a: " << sum << endl;

}


string askNumberInRoman(const string &RomanCharacters){

    string numberInRoman;

    do {
        cout << "Ingrese el numero romano: ";
        getline(cin, numberInRoman);

        bool permitCharacters = true;

        if (all_of(numberInRoman.begin(), numberInRoman.end(), ::isdigit)){
            cout << "No se permiten numero arabicos, vuelva a intentar." << endl;
            continue;
        }

        for (char c : numberInRoman){
            if (RomanCharacters.find(toupper(c)) == string::npos){
                permitCharacters = false;
                cout << "Ingrese solo caracteres permitidos." << endl;
                break;
            }
        }

        if (!permitCharacters) continue;

        for (char &c: numberInRoman) c = ::toupper(c);

        short timesI = count(numberInRoman.begin(), numberInRoman.end(), 'I');
        short timesX =  count(numberInRoman.begin(), numberInRoman.end(), 'X');
        short timesC =  count(numberInRoman.begin(), numberInRoman.end(), 'C');
        short timesM =  count(numberInRoman.begin(), numberInRoman.end(), 'M');

        short timesV =  count(numberInRoman.begin(), numberInRoman.end(), 'V');
        short timesL =  count(numberInRoman.begin(), numberInRoman.end(), 'L');
        short timesD =  count(numberInRoman.begin(), numberInRoman.end(), 'D');

        //regla de la repeticion
        if (timesI > 3 || timesX > 3 || timesC > 3 || timesM > 3){
            cout << "Las letras MCXI, solo se pueden repetir un maximo de 3 veces, vuelva a intenar." << endl;
            continue;
        }

        if (timesV > 1 || timesL > 1 || timesD > 1){
            cout << "Las letras VLD, no se pueden repetir, vuelva a intentar." << endl;
            continue;
        }

        break;
    } while(true);

    return numberInRoman;
}


short getValueLetter(const char& letter){

    if (letter == 'I') return 1;
    else if (letter == 'V') return 5;
    else if (letter == 'X') return 10;
    else if (letter == 'L') return 50;
    else if (letter == 'C') return 100;
    else if (letter == 'D') return 500;
    else if (letter == 'M') return 1000;

    return 0;
}
