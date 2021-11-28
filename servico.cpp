//
// Created by ASUS on 28/11/2021.
//

#include <sstream>
#include "servico.h"

servicos::servicos(tipoServico servico, Funcionario funcionario) : funcionario(funcionario){
    this->tipo = servico;
}

tipoServico servicos::getTipo() {
    return tipo;
}

Funcionario servicos::getFuncionario() {
    return funcionario;
}

string servicos::write() const {
    stringstream oss;
    oss << "Nome: " << funcionario.getNome() << "-- Serviço: " << tipo << "\n Data: " << "dataPlaceholder";
    return oss.str();
}