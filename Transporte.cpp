#include "Transporte.h"
#include <algorithm>

Transporte::Transporte(int distancia, Time time, string tipo) {
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    remove(tipo.begin(), tipo.end(), ' ');

    if(tipo != "metro" && tipo != "autocarro" && tipo != "comboio") throw "Transporte não é do tipo: carro, autocarro ou metro.";

    this->distancia = distancia;
    this->time = time;
    this->tipo = tipo;
}

void Transporte::setDistancia(int distancia) {
    this->distancia = distancia;
}
int Transporte::getDistancia(){
    return distancia;
}
void Transporte::setTime(Time time) {
    this->time = time;
}
Time Transporte::getTime() {
    return time;
}
void Transporte::setTipo(string tipo) {
    this->tipo = tipo;
}
string Transporte::getTipo() {
    return tipo;
}

bool Transporte::operator<(Transporte t2) const{
    if(time.getHora() == t2.getTime().getHora()){ //tem a mesma hora
        return time.getMinuto() < t2.getTime().getMinuto(); //retorna true quando tem menor minuto
    }
    return time.getHora() < t2.getTime().getHora(); //quando as horas sao diferentes
}