#include <string>
#include "Aviao.h"
using namespace std;


Aviao::Aviao(string matricula, int capacidade){
    this->matricula = matricula;
    this->capacidade = capacidade;
}

void Aviao::adicionarPlanoVoo(list<Voo> plano) {
    for(auto v : plano)
        planoVoo.push_back(v);
}

void Aviao::adicionarVoo(Voo v) {
    planoVoo.push_back(v);
}

void Aviao::adicionarServico(servico servico){
    servicosAgendados.push(servico);
}

void Aviao::terminarServico() {
    servicosFeitos.push_back(servicosAgendados.front());
    servicosAgendados.pop();
}

string Aviao::getMatricula() const{
    return matricula;
}

int Aviao::getCapacidade() const{
    return capacidade;
}

list<Voo> Aviao::getPlanoVoo() const{
    return planoVoo;
}

queue<servico> Aviao::getServicosAgendados() const{
    return servicosAgendados;
}

list<servico> Aviao::getServicosFeitos() const{
    return servicosFeitos;
}