//
// Created by ASUS on 28/11/2021.
//

#ifndef PROJETO_AED_FUNCIONARIO_H
#define PROJETO_AED_FUNCIONARIO_H

#include <string>
#include "Data.h"
using namespace std;

class Funcionario {

public:
    Funcionario(string nome, string morada, string contacto, string email, Data data); /// Construtor da classe Funcionario
    string getNome() const; /// Getter do Nome do funcionário
    string getMorada() const; /// Getter da Morada do funcionário
    string getContacto() const; /// Getter do Contacto do funcionário
    string getEmail() const; /// Getter do email do funcionário
    string write() const; /// Writter da classe Funcionário
    bool isOlder(Funcionario f1) const; /// Verificar se um funcionário é mais velho que outro

private:
    string nome; /// Nome do funcionário
    Data dataNasc; /// Data de Nascimento do funcionário
    string morada; /// Morada do funcionário
    string contacto; /// Contacto do funcionário
    string email; /// Email do funcionário
};


#endif //PROJETO_AED_FUNCIONARIO_H
