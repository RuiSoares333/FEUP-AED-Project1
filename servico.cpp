#include <sstream>
#include "servico.h"
#include <fstream>

/// Construtor
/// \param servico para o tipo de serviço efetuado
/// \param funcionario que é o funcionário encarregue do servico
/// \param data agendada para a aplicação do serviço
servico::servico(int id, string servico, string funcionario, Date data){
    this->id = id;
    this->funcionario = funcionario;
    this->tipo = servico;
    this->data = data;
}

/// Getter
/// \return \param tipo de servico
string servico::getTipo() const{
    return tipo;
}

/// Getter
/// \return \param funcionario encarregue do serviço
string servico::getFuncionario() const {
    return funcionario;
}

/// Getter
/// \return \param data agendada para a aplicação do serviço
Date servico::getData() const {
    return data;
}

/// Getter
/// \return \param id que é o numero que identifica o serviço
int servico::getID() const {
    return id;
}

/// Setter
/// \param funcionario que é o novo funcionário encarregue de executar o serviço
void servico::setFuncionario(string funcionario) {
    this->funcionario = funcionario;
}

/// Setter
/// \param novoTipo que é o novo tipo de serviço, igual ou diferente ao anterior
void servico::setTipo(string novoTipo) {
    tipo = novoTipo;
}

///// Writer
///// \return de uma string com os atributos do ID - Funcionario - Tipo - YYYY-MM-DD
string servico::write() const {
    stringstream oss;
    oss << "ID: " << id << " - Funcionario: " << funcionario << " - Tipo: "<< tipo << " - Data: " << data.getYear() << "-" << data.getMonth() << "-" << data.getDay() << endl;
    return oss.str();
}