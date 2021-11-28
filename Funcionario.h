//
// Created by ASUS on 28/11/2021.
//

#ifndef PROJETO_AED_FUNCIONARIO_H
#define PROJETO_AED_FUNCIONARIO_H

#include <string>
using namespace std;

class Funcionario {
    string nome;
    //date dataNasc;
    string morada;
    string contacto;
    string email;
public:
//    Funcionario();
    Funcionario(string nome, string morada, string contacto, string email);
    string getNome() const;
    string getMorada() const;
    string getContacto() const;
    string getEmail() const;
    string write() const;
    bool isOlder(Funcionario f1) const;
};


#endif //PROJETO_AED_FUNCIONARIO_H
