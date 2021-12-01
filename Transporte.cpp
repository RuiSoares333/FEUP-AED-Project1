#include "Transporte.h"
#include <algorithm>

Transporte::Transporte(int distancia, Horario horario, string tipo) {
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    remove(tipo.begin(), tipo.end(), ' ');

    if(tipo != "metro" && tipo != "autocarro" && tipo != "comboio") throw "Transporte não é do tipo: carro, autocarro ou metro.";

    this->distancia = distancia;
    this->horario = horario;
    this->tipo = tipo;
}

void Transporte::setDistancia(int distancia) {
    this->distancia = distancia;
}
int Transporte::getDistancia(){
    return distancia;
}
void Transporte::setHorario(Horario horario) {
    this->horario = horario;
}
Horario Transporte::getHorario() {
    return horario;
}
void Transporte::setTipo(string tipo) {
    this->tipo = tipo;
}
string Transporte::getTipo() {
    return tipo;
}