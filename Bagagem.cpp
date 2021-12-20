//
// Created by PC on 14/12/2021.
//

#include "Bagagem.h"

/// Constructor
/// Construtor Vazio de Bagagem com Valores Default
Bagagem::Bagagem() {
    this->comprimento = 0;
    this->largura = 0;
    this->altura = 0;
    this->peso = 0;
}

/// Constructor
/// Construtor completo com \param comprimento, \param largura, \param altura e \param peso
Bagagem::Bagagem(float comprimento, float largura, float altura, float peso) {
    this->comprimento =  comprimento;
    this->largura = largura;
    this->altura = altura;
    this->peso = peso;
}

/// Getter
/// \return \param comprimento
float Bagagem::getComprimento() const {
    return comprimento;
}

/// Getter
/// \return \param largura
float Bagagem::getLargura() const {
    return largura;
}

/// Getter
/// \return \param altura
float Bagagem::getAltura() const {
    return altura;
}

/// Getter
/// \return \param peso
float Bagagem::getPeso() const {
    return peso;
}
