//
// Created by PC on 28/11/2021.
//

#include <string>
#include "Voo.h"

Voo::Voo(int numVoo, string dataPartida, int duracaoVoo, list<Passageiro> passageiros){
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracaoVoo = duracaoVoo;
    this->passageiros = passageiros;
}
int Voo::getNum() const{
    return numVoo;
}
string Voo::getData() const {
    return dataPartida;
}
int Voo::getDuracao() const {
    return duracaoVoo;
}
list<Passageiro> Voo::getPassageiros() const {
    return passageiros;
}
void Voo::setNum(int num) {
    numVoo = num;
}
void Voo::setData(string data) {
    dataPartida = data;
}
void Voo::setDuracao(int dur){
    duracaoVoo = dur;
}