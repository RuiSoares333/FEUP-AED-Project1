#include <sstream>
#include "servico.h"

servico::servico(tipoServico servico, Funcionario funcionario, Data data) : funcionario(funcionario){
    this->tipo = servico;
    this->data = data;
}

tipoServico servico::getTipo() const{
    return tipo;
}

Funcionario servico::getFuncionario() const {
    return funcionario;
}

Data servico::getData() const {
    return data;
}

string servico::write() const {
    stringstream oss;
    oss << "Nome: " << funcionario.getNome() << "-- Serviço: " << tipo << "\n Data: " << "dataPlaceholder";
    return oss.str();
}