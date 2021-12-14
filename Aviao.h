#ifndef MAIN_CPP_AVIAO_H
#define MAIN_CPP_AVIAO_H

#include <string>
#include "Voo.h"
#include "servico.h"
#include <queue>

using namespace std;

class Aviao {
public:
    /// Construtor
    /// \param matricula do aviao
    /// \param capacidade de passageiros do aviao
    Aviao(string matricula, int capacidade);

    ///
    /// \param plano é uma lista de voos
    /// é adicionado ao plano de voos todos os voos dentro da lista \param plano
    void adicionarPlanoVoo(list<Voo> plano);

    ///
    /// \param v é um voo que vai ser adicionado à lista de voos planeados
    void adicionarVoo(Voo v);

    ///
    /// \param servico é um serviço que vai ser adicionado à lista de serviços agendados
    void adicionarServico(servico servico);

    /// termina o serviço na front() da queue de serviços agendados
    void terminarServico();

    ///
    /// \return \param matricula do avião
    string getMatricula() const;

    ///
    /// \return \param capacidade do avião
    int getCapacidade() const;

    ///
    /// \return \param planoVoo que retorna os voos planeados
    list<Voo> getPlanoVoo() const;

    ///
    /// \return \param sericosAgendados
    queue<servico> getServicosAgendados() const;
    list<servico> getServicosFeitos() const;

private:
    string matricula;
    int capacidade;
    list<Voo> planoVoo;
    queue<servico> servicosAgendados;
    list<servico> servicosFeitos;
};


#endif //MAIN_CPP_AVIAO_H
