//
// Created by ASUS on 18/12/2021.
//

#ifndef PROJETO_AED_BASEDADOS_H
#define PROJETO_AED_BASEDADOS_H

#include "Aeroporto.h"
#include "servico.h"
#include "Aviao.h"
#include "Voo.h"
#include <iomanip>

class BaseDados {
public:
    // Loaders
    void loadAll();
    bool loadAirports();
    void loadServicos();
    void loadAvioes();
    bool loadVoos();

    // Sorters
    void sortServicos();
    void sortAvioes();
    void sortVoos();
    void airportSort();

    // Drawers
    void drawServicos() const;
    void drawAvioes(list<Aviao> lista) const;
    void drawAvioesCap() const;
    void drawAvioesVoo() const;
    void drawAvioesSerAg() const;
    void drawAvioesSerTer() const;
    void drawVoos(list<Voo> auxVoos) const;
    void drawVoosData() const;
    void drawVoosDuracao() const;
    void drawVoosPassageiros() const;
    void drawParcialVoosData(Date d1, Date d2) const;
    void transportDraw(Aeroporto &aeroporto);
    void transporteDrawParcial(Aeroporto &aeroporto, Date d1, Date d2, Time t1, Time t2);
    void airportDraw();
    void servicosDraw(string tipo);

    // Getters
    list <Aeroporto> getAeroportos() const;
    list <servico> getServicos() const;
    list <Aviao> getAvioes() const;
    list <Voo> getVoos() const;

    // Savers
    void saveAll();
    bool saveAirports();
    void saveServicos();
    void saveAvioes();
    bool saveVoos();

    // Adders
    void addAirport(Aeroporto aeroporto);
    void addServico(servico servico);
    void addAviao(Aviao a);
    void addVoo(Voo v);
    bool addTransporte(Aeroporto aero, Transporte trans);

    // Removers
    bool removeAirport(Aeroporto aeroporto);
    void removeAviao(string matricula);
    bool removeVoo(int numVoo);
    bool removeTransporte(Aeroporto &aeroporto, Transporte transporte);

    // Updaters
    bool updateAirport(Aeroporto aeroporto, string nome, string cidade, string pais);
    bool updateTransporte(Aeroporto aeroporto, Transporte transporte, int distancia, string tipo, Time time, Date date);
    bool updateAviaoVoo(string matricula, Voo voo); //sem querer apaguei isto srry - lucas no worries - rui
    bool updateAviaoServicoCriar(string matricula, servico ser);
    bool updateAviaoServicoTerminar(string matricula);
    bool updateVoo(int numVoo_s, int numVoo_p, Date data, float duracao, TransporteBagagem t, Aeroporto a1, Aeroporto a2, list<Passageiro> passageiros);

private:
    list<Aeroporto> aeroportos;
    list<servico> servicos;
    list<Aviao> avioes;
    list<Voo> voos;
};


#endif //PROJETO_AED_BASEDADOS_H
