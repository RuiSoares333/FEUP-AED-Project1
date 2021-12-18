#ifndef MAIN_CPP_AVIAO_H
#define MAIN_CPP_AVIAO_H

#include <string>
#include "Voo.h"
#include "servico.h"
#include <queue>

using namespace std;

class Aviao {
public:
    Aviao();
    Aviao(string matricula, int capacidade);
    void adicionarPlanoVoo(list<Voo> plano);
    void adicionarVoo(Voo v);
    void addServAgendado(servico servico);
    void terminarServico();
    void addServCompleto(servico s);
    bool addPassageiro(int numVoo, Passageiro pass);
    bool const operator < (Aviao a2) const;

    // Getters
    string getMatricula() const;
    int getCapacidade() const;
    list<Voo> getPlanoVoo() const;
    list<servico> getServicosAgendados() const;
    list<servico> getServicosFeitos() const;

    // Setters
    void setPlanoVoo(list<Voo> novoPlano);
    void setServicosAgendados(list<servico> novosServicos);
    void setServicosCompletos(list<servico> novosServicos);

    // Writer
    string write()const;

private:
    string const matricula;
    list<Voo> planoVoo;
    list<servico> servicosAgendados;
    list<servico> servicosFeitos;
    int const capacidade;
};


#endif //MAIN_CPP_AVIAO_H