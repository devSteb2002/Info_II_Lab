#ifndef RED_H
#define RED_H

#include <map>
#include <vector>
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
        void calculateShortWay(string fromKey, string toKey);
        void setRed(const map<string, map<string, unsigned short> > &newRed);

        ~Red();

    private:
        map<string, map<string, unsigned short>> red;

        // map<string, map<string, unsigned short>> red = {
        //     { "A" , { {"B" , 4}, {"C", 10}, {"D", 5} }},
        //     { "B" , { { "A", 4 }, {"D", 1}, { "C", 3}}},
        //     { "C" , { {"A", 10}, {"B", 3}, {"D", 2}}},
        //     { "D", { { "A", 5 }, {"B", 1}, {"C", 2}}},
        //     { "E", { { "D" , 4}}}
        // };

         vector<string> waysToKey;
         vector<vector<string>> ways;

};

#endif // RED_H
