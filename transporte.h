#ifndef PROJETO_AED_TRANSPORTE_H
#define PROJETO_AED_TRANSPORTE_H
#include <string>
#include "Horario.h"
using namespace std;


class Transporte {
public:
    Transporte(int distancia, Horario horario, string tipo); //construtor, converte todas as strings tipo para lowercase e remove espacos, throws uma excecao quando o tipo é diferente de "metro", "comboio" ou "autocarro"
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
