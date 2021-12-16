#include <string>
#include "Aviao.h"
#include <sstream>
using namespace std;

/// Construtor
/// \param m matricula do aviao
/// \param c capacidade de passageiros do aviao
Aviao::Aviao(string m, int c): matricula(m), capacidade(c) {}


/// \param plano é uma lista de voos
/// é adicionado ao plano de voos todos os voos dentro da lista \param plano
void Aviao::adicionarPlanoVoo(list<Voo*> plano) {
    for(auto v : plano)
        planoVoo.push_back(v);
}


/// \param v é um voo que vai ser adicionado à lista de voos planeados
void Aviao::adicionarVoo(Voo *v) {
    planoVoo.push_back(v);
}

/// \param servico é um serviço que vai ser adicionado à lista de serviços agendados
void Aviao::adicionarServico(servico *servico){
    servicosAgendados.push(servico);
}

/// termina o serviço na front() da queue de serviços agendados
void Aviao::terminarServico() {
    servicosFeitos.push_back(servicosAgendados.front());
    servicosAgendados.pop();
}

/// Getter
/// \return \param matricula do avião
string Aviao::getMatricula() const{
    return matricula;
}

/// Getter
/// \return \param capacidade do avião
int Aviao::getCapacidade() const{
    return capacidade;
}

/// Getter
/// \return \param planoVoo que retorna os voos planeados
list<Voo*> Aviao::getPlanoVoo() const{
    return planoVoo;
}

/// Getter
/// \return \param sericosAgendados que retorna a queue de serviços agendados
queue<servico*> Aviao::getServicosAgendados() const{
    return servicosAgendados;
}

/// Getter
/// \return \param servicosFeitos que retorna a lista de serviços já feitos
list<servico*> Aviao::getServicosFeitos() const{
    return servicosFeitos;
}

/// Setter
/// \param novoPlano passsa a ser o novo plano de voo definido para o avião
void Aviao::setPlanoVoo(list<Voo *> novoPlano) {
    planoVoo = novoPlano;
}

/// Setter
/// \param novosServicos passam a ser os novos serviços agendados para o avião
void Aviao::setServicosAgendados(queue<servico *> novosServicos) {
    servicosAgendados = novosServicos;
}


///
/// \return uma string com os atributos base do avião: Matricula:a - Capacidade: c
string Aviao::write() const {
    stringstream oss;
    oss << "Matricula: " << matricula << " - Capacidade: " << capacidade;
    return oss.str();
}