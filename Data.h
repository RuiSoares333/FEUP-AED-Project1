//
// Created by ASUS on 14/12/2021.
//

#ifndef PROJETO_AED_DATA_H
#define PROJETO_AED_DATA_H

#include "Time.h"
#include <string>

using namespace std;

class Data {
public:
    Data(int ano, int mes, int dia);
    Data(int ano, int mes, int dia, Time tempo);

    int getAno() const;
    int getMes() const;
    int getDia() const;
    Time getTempo() const;
    string write() const;
private:
    int ano;
    int mes;
    int dia;
    Time tempo;
};


#endif //PROJETO_AED_DATA_H
