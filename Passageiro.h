//
// Created by PC on 28/11/2021.
//

#ifndef PROJETO_AED_PASSAGEIRO_H
#define PROJETO_AED_PASSAGEIRO_H

#include <string>

using namespace std;

class Passageiro {
public:
    Passageiro(string nome, int bilhete);
    string getNome () const;
    int getBilhete() const;
    void setNome(string nome);
    void setBilhete(int num);
private:
    string nome;
    int bilhete; //pode vir a ser string se houver necessidade de mudar o formato do numero do bilhete
};


#endif //PROJETO_AED_PASSAGEIRO_H
