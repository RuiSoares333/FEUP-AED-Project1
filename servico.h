#ifndef PROJETO_AED_SERVICOS_H
#define PROJETO_AED_SERVICOS_H


#include <string>
#include "Date.h"

using namespace std;

class servico {

public:
    servico(int id, string tipo, string funcionario, Date data);

    // Getters
    string getTipo() const;
    Date getData() const;
    string getFuncionario() const;
    int getID() const;

    bool const operator < (servico s2) const;

    // Setters
    void setTipo(string novoTipo);
    void setFuncionario(string funcionario);

    // Writer
    string write() const ;
    bool saveFile ();
    bool loadFile ();

private:
    int id;
    string tipo; /// Tipo de serviço que pode ser realizado (Manutenção/Limpeza)
    Date data; /// Data em que o serviço é realizado
    string funcionario; /// Funcionário responsável pelo serviço
};


#endif //PROJETO_AED_SERVICOS_H