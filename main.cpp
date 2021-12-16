#include <iostream>
#include "Transporte.h"
#include "Aeroporto.h"
#include <list>
using namespace std;

list<Aeroporto> aeroportos;

bool loadAirports();

int main() {
    return 0;
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