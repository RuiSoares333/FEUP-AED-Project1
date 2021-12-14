#ifndef PROJETO_AED_SERVICOS_H
#define PROJETO_AED_SERVICOS_H


#include <string>
#include "Funcionario.h"
#include "Data.h"

using namespace std;
enum tipoServico {MANUTENCAO, LIMPEZA};

class servico {

public:
    servico(tipoServico tipo, Funcionario funcionario, Data data); /// Construtor da classe servico
    tipoServico getTipo() const; /// Getter do tipo de serviço
    Data getData() const; /// Getter da data do serviço
    Funcionario getFuncionario() const; /// Getter do funcionário responsável pelo serviço
    string write() const ; /// Writter da classe servico

private:
    tipoServico tipo; /// Tipo de serviço que pode ser realizado (Manutenção/Limpeza)
    Data data; /// Data em que o serviço é realizado
    Funcionario funcionario; /// Funcionário responsável pelo serviço
};


#endif //PROJETO_AED_SERVICOS_H
