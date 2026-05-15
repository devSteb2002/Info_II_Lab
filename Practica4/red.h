#ifndef RED_H
#define RED_H

#include <map>
#include <iostream>

using namespace std;

class Red{
    public:
        Red();

        void showRoutters();
        bool alreadyExistRouter(string name);
        void addNewRouter(string name);
        void addLinks(string key,  string name, unsigned short value);
        void updateRouter(string key, string key2, unsigned short value);
        void deleteRouter(string key);
        void showRouterByName(string key_);

    private:
        map<string, map<string, unsigned short>> red = {
            { "A" , { {"B" , 3}, {"C", 4} }},
            { "B" , { { "A", 3 }, {"C", 3}}}
        };

};

#endif // RED_H
