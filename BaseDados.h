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
    void loadAll();
    bool loadAirports();
    void loadServicos();
    void loadAvioes();
    bool loadVoos();

    const list <Aeroporto> &getAeroportos() const;
    const list <servico> &getServicos() const;
    const list <Aviao> &getAvioes() const;
    const list <Voo> &getVoos() const;

    void saveAll();
    bool saveAirports();
    void saveServicos();
    void saveAvioes();
    bool saveVoos();

    void airportSort();
    void airportDraw();
private:
    list<Aeroporto> aeroportos;
    list<servico> servicos;
    list<Aviao> avioes;
    list<Voo> voos;
};


#endif //PROJETO_AED_BASEDADOS_H
