//
// Created by PC on 14/12/2021.
//

#include "Bagagem.h"

Bagagem::Bagagem() {
    this->comprimento = 0;
    this->largura = 0;
    this->altura = 0;
    this->peso = 0;
}

Bagagem::Bagagem(float comprimento, float largura, float altura, float peso) {
    this->comprimento =  comprimento;
    this->largura = largura;
    this->altura = altura;
    this->peso = peso;
}

float Bagagem::getComprimento() const {
    return comprimento;
}

float Bagagem::getLargura() const {
    return largura;
}

float Bagagem::getAltura() const {
    return altura;
}

float Bagagem::getPeso() const {
    return peso;
}
