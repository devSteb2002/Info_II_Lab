#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>

//LZ78
char ***initLZ78(int &rows,  const std::string type, int &cols);
void saveDataLZ78(std::string type, const std::string *data, const int & rows);
std::string* gettDataLZ78(int & rows);
void generateJSONDecrypt(char **&JSON, int& cols, const char& indice, const char& letter);
void descomLZ78(char ***JSON, const int &rows, short* cols);

//RLE
std::string* initRLE(int &rows_);
void saveData(std::string type, std::string *dataToEncryptRLE, int &rows);
std::string* getDataEncrypt(int & rows);
void descomRLe(std::string &chain);


#endif // DEFINITION_H
