#include "red.h"

Red::Red() {}


void Red::showRoutters(){

    for (const auto& [key, intern] : this->red){
        cout << key  << endl;

        for(const auto& [k2, v] : intern){
            std::cout <<  "   " <<   k2 << " : "<< v << std::endl;
        }
    }
}


bool Red::alreadyExistRouter(string name){
    bool exist = false;
    for (const auto& [key, intern] : this->red){
        if (key == name) exist = true;
    }
    return exist;
}

void Red::addNewRouter(string name){
    this->red[name];
}

void Red::addLinks(string key,  string name, unsigned short value){
    if (key == name){
        this->red[key][name] = 0;
        return;
    }

    this->red[key][name] = value;
    this->red[name][key] = value;
}

void Red::updateRouter(string key, string key2, unsigned short value){
    this->red[key][key2] = value;
    this->red[key2][key] = value;
}

void Red::deleteRouter(string key_){
    for(auto& [key, intern] : this->red) intern.erase(key_);
    this->red.erase(key_);
}

void Red::showRouterByName(string key_){
    for (const auto& [key, intern] : this->red){

        if (key == key_){

            cout << "-----------------------------------------" << endl;
            cout << " Router: " << key << endl;
            cout << "-----------------------------------------" << endl;

            for(const auto& [k2, v] : intern){
                cout << k2 << "  : "  << v << endl;
            }
        }
    }


}
