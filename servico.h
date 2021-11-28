#ifndef PROJETO_AED_SERVICOS_H
#define PROJETO_AED_SERVICOS_H


#include <string>
#include "Funcionario.h"

using namespace std;
enum tipoServico {MANUTENCAO, LIMPEZA};

class servico {

public:
//    servicos();
    servico(tipoServico tipo, Funcionario funcionario); /// Construtor da classe servico
    tipoServico getTipo(); /// Getter do tipo de serviço
//    string getData(); /// Getter da data do serviço
    Funcionario getFuncionario(); /// Getter do funcionário responsável pelo serviço
    string write() const; /// Writter da classe servico

private:
    tipoServico tipo; /// Tipo de serviço que pode ser realizado (Manutenção/Limpeza)
    //date data; /// Data em que o serviço é realizado
    Funcionario funcionario; /// Funcionário responsável pelo serviço
};


#endif //PROJETO_AED_SERVICOS_H
