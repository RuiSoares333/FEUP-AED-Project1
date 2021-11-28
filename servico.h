//
// Created by ASUS on 28/11/2021.
//

#ifndef PROJETO_AED_SERVICOS_H
#define PROJETO_AED_SERVICOS_H


#include <string>
#include "Funcionario.h"

using namespace std;
enum tipoServico {MANUTENCAO, LIMPEZA};
class servicos {
    tipoServico tipo;
    //date data;
    Funcionario funcionario;

public:
//    servicos();
    servicos(tipoServico tipo, Funcionario funcionario);
    tipoServico getTipo();
//    string getData();
    Funcionario getFuncionario();
    string write() const;
};


#endif //PROJETO_AED_SERVICOS_H
