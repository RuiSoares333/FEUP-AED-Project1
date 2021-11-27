#include "Horario.h"

Horario::Horario(vector<vector<int>> horas){
    this->horas = horas;
}
void Horario::setHoras(vector<vector<int>> horas) {
    this->horas = horas;
}
vector<vector<int>> Horario::getHoras() {
    return horas;
}