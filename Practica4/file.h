#ifndef FILE_H
#define FILE_H

#include <iostream>
#include "red.h"


using namespace std;

class File{
    public:
        File(Red*& red);

        void loadMap();
        void saveMap();

        ~File();
    private:
        Red* red = nullptr;

};

#endif // FILE_H
