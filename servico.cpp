#include <sstream>
#include "servico.h"

servico::servico(tipoServico servico, Funcionario funcionario) : funcionario(funcionario){
    this->tipo = servico;
}

tipoServico servico::getTipo() {
    return tipo;
}

Funcionario servico::getFuncionario() {
    return funcionario;
}

string servico::write() const {
    stringstream oss;
    oss << "Nome: " << funcionario.getNome() << "-- Serviço: " << tipo << "\n Data: " << "dataPlaceholder";
    return oss.str();
}