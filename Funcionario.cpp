//
// Created by ASUS on 28/11/2021.
//

#include <sstream>
#include "Funcionario.h"


//Funcionario::Funcionario() {}

Funcionario::Funcionario(string nome, string morada, string contacto, string email) {
    this->nome = nome;
    this->morada = morada;
    this->contacto = contacto;
    this->email = email;
}

string Funcionario::getNome() const {
    return nome;
}

string Funcionario::getMorada() const {
    return morada;
}

string Funcionario::getContacto() const {
    return contacto;
}

string Funcionario::getEmail() const {
    return email;
}

string Funcionario::write() const {
    stringstream oss;
    oss << "Nome: " << nome << "\n Age: " << morada << "\n Email: " << email;
    return oss.str();
}
