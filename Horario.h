#ifndef PROJETO_AED_HORARIO_H
#define PROJETO_AED_HORARIO_H
#include <vector>
using namespace std;

class Horario {
public:
    //assume que os horarios sao semanais e constantes
    //isto é, tem varias horas de serviço por dia, 7 dias por semana, iguais todas as semanas

    Horario(vector<vector<int>> horas); //construtor que tem um vetor bidimencional como parametro
    void setHoras(vector<vector<int>> horas);
    vector<vector<int>> getHoras();
private:
    vector<vector<int>> horas; //guardam-se todas as horas de servico, por todos os 7 dias da semana
    //horas[0] é o vetor que contem todas as horas no sabado
    //horas[1] é no domingo
    //horas[6] é na sexta feira
};
#endif //PROJETO_AED_HORARIO_H
