#ifndef PROJETO_AED_TRANSPORTE_H
#define PROJETO_AED_TRANSPORTE_H
#include <string>
#include "time.h"
using namespace std;


class Transporte {
public:
    Transporte(int distancia, Time time, string tipo); //construtor, converte todas as strings tipo para lowercase e remove espacos, throws uma excecao quando o tipo é diferente de "metro", "comboio" ou "autocarro"
    void setDistancia(int distancia);
    int getDistancia();
    void setTime(Time time);
    Time getTime();
    void setTipo(string tipo);
    string getTipo();
    bool operator<(Transporte t2) const;

private:
    int distancia;
    Time time;
    string tipo;
};


#endif //PROJETO_AED_TRANSPORTE_H
