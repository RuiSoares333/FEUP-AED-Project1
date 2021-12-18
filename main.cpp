#include <iostream>
#include "Transporte.h"
#include "Aeroporto.h"
#include "Voo.h"
#include <list>
using namespace std;

list<Aeroporto> aeroportos;
list<Voo> voos;

bool loadAirports();
bool saveAirports();
bool loadVoos();
bool saveVoos();

int main() {
    loadVoos();
    return 0;
}

bool loadVoos() {
    int numVoo;
    ifstream load;
    load.open("voo_all_save.txt");
    if (load.is_open()) {
        while (load >> numVoo) {
            Voo voo;
            voo.setNum(numVoo);
            voo.loadFile();
            voos.push_back(voo);
        }
        return true;
    }
    return false;
}

bool saveVoos() {
    ofstream save;
    save.open("voo_all_save.txt", ofstream::trunc);
    if (save.is_open()) {
        for (Voo voo : voos) {
            voo.saveFile();
        }
        return true;
    }
    return false;
}

bool loadAirports(){
    string nome, cidade, pais;
    ifstream loadStream;
    loadStream.open("aeroporto_all_save.txt");
    if(loadStream.is_open()){
       while(loadStream >> nome >> cidade >> pais){
           Aeroporto  aero(nome, pais, cidade);
           aero.loadFile();
           aeroportos.push_back(aero);
       }
       return true;
    }
    return false;
}

bool saveAirports(){
    ofstream saveStream;
    saveStream.open("aeroporto_all_save.txt", ofstream ::trunc);
    if(saveStream.is_open()){
        for(Aeroporto aeroporto: aeroportos){
            aeroporto.saveFile();
        }
        return true;
    }
    return false;
}