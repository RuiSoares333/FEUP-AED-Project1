//
// Created by PC on 28/11/2021.
//

#include "Passageiro.h"

Passageiro::Passageiro(string nome, int bilhete) {
    this->nome = nome;
    this->bilhete = bilhete;
}
string Passageiro::getNome () const {
    return nome;
}
int Passageiro::getBilhete() const {
    return bilhete;
}
void Passageiro::setNome(string nome) {
    this->nome = nome;
}
void Passageiro::setBilhete(int num) {
    bilhete = num;
}