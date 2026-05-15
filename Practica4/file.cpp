#include "file.h"
#include <fstream>
#include <map>

File::File(Red *&red) : red(red) {}

void File::loadMap(){

    ifstream File("Red.txt");
    map<string, map<string, unsigned short>> red;

    if (File.is_open()){

        string line;

        while(getline(File, line)){

            size_t start = line.find('{') + 1;
            size_t end = line.find(':');
            string key = line.substr(start, end - start);

            size_t pos = line.find(':') + 1;

            while(true){

                size_t open = line.find('{', pos);

                if(open == string::npos)
                    break;

                size_t colon = line.find(':', open);
                size_t close = line.find('}', colon);

                string key_ = line.substr(open + 1, colon - open - 1);
                string value = line.substr(colon + 1, close - colon - 1);

                red[key][key_] = static_cast<unsigned short>(stoi(value));

                pos = close + 1;
            }
        }
    }

    this->red->setRed(red);
}

void File::saveMap(){

}

