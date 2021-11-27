#ifndef PROJETO_AED_TRANSPORTE_H
#define PROJETO_AED_TRANSPORTE_H
#include <string>
#include "Horario.h"
using namespace std;


class Transporte {
public:
    //tipo tem de ser verificado como metro, comboio, autocarro antes da criacao do objeto
    Transporte(int distancia, Horario horario, string tipo);
    void setDistancia(int distancia);
    int getDistancia();
    void setHorario(Horario horario);
    Horario getHorario();
    void setTipo(string tipo);
    string getTipo();

private:
    int distancia;
    Horario horario;
    string tipo;
};


#endif //PROJETO_AED_TRANSPORTE_H
