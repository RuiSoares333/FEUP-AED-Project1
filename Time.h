#ifndef PROJETO_AED_TIME_H
#define PROJETO_AED_TIME_H

#include <string>

using namespace std;


class Time {
private:
    int hora, minuto; //formato hh mm
public:
    Time(); //default 0:0
    Time(int hora, int minuto);
    void setHora(int hora);
    void setMinuto(int minuto);
    int getHora() const;
    int getMinuto() const;
    string write() const;
};


#endif //PROJETO_AED_TIME_H
