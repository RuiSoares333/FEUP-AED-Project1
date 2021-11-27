#include "Transporte.h"

Transporte::Transporte(int distancia, Horario horario, string tipo) {
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