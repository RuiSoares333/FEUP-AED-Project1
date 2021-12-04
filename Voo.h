//
// Created by PC on 28/11/2021.
//

#ifndef PROJETO_AED_VOO_H
#define PROJETO_AED_VOO_H

#include <string>
#include <list>
#include "Passageiro.h"

using namespace std;

class Voo {
public:
    Voo(int numVoo, string dataPartida, int duracaoVoo, list<Passageiro> passageiros);
    int getNum() const;
    string getData() const ;
    int getDuracao() const;
    list<Passageiro> getPassageiros() const;
    void setNum(int num);
    void setDuracao(int dur);
    void setData(string data);
    void addPassageiro(Passageiro passageiro); //???
    void removePassageiro(); //???

private:
    int numVoo;
    string dataPartida; //se houver classe data futuramente alterar
    int duracaoVoo;
    list<Passageiro> passageiros;


};


#endif //PROJETO_AED_VOO_H
