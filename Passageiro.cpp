//
// Created by PC on 28/11/2021.
//
#include "Passageiro.h"
/// Default constructor
Passageiro::Passageiro() {
    this->nome = "";
    this->id = 0;
}
/// Constructor
/// \param nome nome do passageiro
/// \param id id do passageiro
/// \param bilhetes vetor dos bilhetes adquiridos pelo passageiro
/// \param bagagens vetor das bagagens que pertencem ao passageiro
Passageiro::Passageiro(string nome, int id, vector<Bilhete> bilhetes, vector<Bagagem> bagagens) {
    this->nome = nome;
    this->id = id;
    this->bilhetes = bilhetes;
    this->bagagens = bagagens;
}
/// Getter
/// \return retorna o nome do passageiro
string Passageiro::getNome () const {
    return nome;
}
/// Getter
/// \return retorna o id do passageiro
int Passageiro::getId () const {
    return id;
}
/// Getter
/// \return retorna o vetor de bilhetes do passageiro
vector<Bilhete> Passageiro::getBilhetes() const {
    return bilhetes;
}
/// Getter
/// \return retorna o vetor de bagagens do passageiro
vector<Bagagem> Passageiro::getBagagens() const {
    return bagagens;
}