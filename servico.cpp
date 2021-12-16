#include <sstream>
#include "servico.h"

///
/// \param servico para o tipo de serviço efetuado
/// \param funcionario que é o funcionário encarregue do servico
/// \param data agendada para a aplicação do serviço
servico::servico(tipoServico servico, Funcionario funcionario, Date data){
    this->funcionario = funcionario;
    this->tipo = servico;
    this->data = data;
}

///
/// \return tipo de servico
tipoServico servico::getTipo() const{
    return tipo;
}

///
/// \return funcionario encarregue do serviço
Funcionario servico::getFuncionario() const {
    return funcionario;
}

///
/// \return data agendada para a aplicação do serviço
Date servico::getData() const {
    return data;
}

///
/// \return de uma string com os atributos do funcionário -- serviço: Data
string servico::write() const {
    stringstream oss;
    oss << "Nome: " << funcionario.getNome() << "-- Serviço: " << tipo << "\n Data: " << "dataPlaceholder";
    return oss.str();
}