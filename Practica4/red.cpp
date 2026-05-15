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

void Red::calculateShortWay(string fromKey, string toKey){

    this->waysToKey.clear();
    vector<vector<string>>().swap(this->ways);
    this->ways.clear();

    for (const auto& [key, value] : this->red){ // encontrar los router que lleguen al deseado

        for (const auto& [key_, value_] : this->red[key]){
            if (key_ == toKey){
                this->waysToKey.push_back(key);
                break;
            }
        }
    }

    for (const auto& item_ : this->waysToKey){
        if (item_ == fromKey){
            this->ways.push_back({ fromKey, toKey });
            continue;
        }

        if (this->red[item_].find(fromKey) != this->red[item_].end()){ // si existe la conexion con el router de origen
            if (item_ != toKey)  this->ways.push_back({  fromKey, item_, toKey  });
        }
        else {
            for (const auto& [keyInside, valueInside] : this->red[item_]){
                if (keyInside == toKey) continue;

                if (this->red[keyInside].find(fromKey) != this->red[keyInside].end()){
                    this->ways.push_back({ fromKey, keyInside,  item_ , toKey });
                    break;
                }
            }
        }
    }

    cout << "Para llegar a " << toKey << "  se tiene " << this->ways.size() <<" caminos." << endl;

    for (unsigned short i = 0; i < this->ways.size(); i++){
        cout << "Camino #" << (i +1) << ": ";

        unsigned short cost = 0;
        for (unsigned short c = 0; c < this->ways[i].size(); c++){
            string key = this->ways[i][c];
            string nextKey =  (c + 1) >= this->ways[i].size() ? "--{}$%6T" :  this->ways[i][c + 1];

            if (nextKey != "--{}$%6T"){
                cost += this->red[key][nextKey];
                cout << key << " ->  ";
            }else cout << key;

        }

        cout << "    |   Costo: " << cost << endl;
    }

    // for (const auto& ways: this->ways){
    //     for (const auto& way: ways){
    //         cout << way << " ->  ";
    //     }
    //     cout << endl;

    // }
}

void Red::setRed(const map<string, map<string, unsigned short> > &newRed){
    red = newRed;
}

Red::~Red(){
    this->waysToKey.clear();
    vector<vector<string>>().swap(this->ways);
    this->ways.clear();
    map<string, map<string, unsigned short>>().swap(this->red);
}
