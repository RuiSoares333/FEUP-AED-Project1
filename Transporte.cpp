#include "Transporte.h"
#include <algorithm>

/// Construtor
/// \param distância
/// \param time
/// \parâmetro String tipo
/// \parâmetro Date date
/// \converte o tipo para letra minúscula e remove espaços
/// \após este passo, se o tipo for diferente de "metro", "autocarro" e "comboio" dá a exceção:
/// \"Transporte não é do tipo: carro, autocarro ou metro"
/// \cria um objeto da classe Transporte com os parametros distância, time, tipo e date
Transporte::Transporte(int distancia, Time time, string tipo, Date date){
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    remove(tipo.begin(), tipo.end(), ' ');

    if(tipo != "metro" && tipo != "autocarro" && tipo != "comboio") throw ("Transporte não é do tipo: carro, autocarro ou metro.");

    this->distancia = distancia;
    this->time = time;
    this->tipo = tipo;
    this->date = date;
}

/// Setter
/// \param int distancia
/// \muda \param distancia do transporte ao aeroporto
void Transporte::setDistancia(int distancia) {
    this->distancia = distancia;
}

/// Getter
/// \return \param distancia do transporte ao aeroporto
int Transporte::getDistancia() const{
    return distancia;
}

/// Setter
/// \param time
/// \muda \param time do transporte
void Transporte::setTime(Time time) {
    this->time = time;
}

/// Getter
/// \return \param tempo do transporte
Time Transporte::getTime() const{
    return time;
}

/// Setter
/// \param tipo
/// \converte o tipo para letra minúscula e remove espaços
/// \após este passo, se o tipo for diferente de "metro", "autocarro" e "comboio" dá a exceção:
/// \"Transporte não é do tipo: carro, autocarro ou metro"
/// \muda o tipo do transporte
void Transporte::setTipo(string tipo) {
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    remove(tipo.begin(), tipo.end(), ' ');

    if(tipo != "metro" && tipo != "autocarro" && tipo != "comboio") throw ("Transporte não é do tipo: carro, autocarro ou metro.");

    this->tipo = tipo;
}

/// Getter
/// \return \param tipo do transporte
string Transporte::getTipo() const{
    return tipo;
}

/// Operator<
/// \se as datas forem iguais retorna time < t2.getTime()
/// \caso contrário retorna data < t2.getDate()
bool const Transporte::operator<(Transporte t2) const{
    if(date == t2.getDate()) return time < t2.getTime();
    return date < t2.getDate();
}

/// Getter
/// \return \param data do transporte
const Date &Transporte::getDate() const {
    return date;
}

/// Setter
/// Muda o \param data para uma nova data
void Transporte::setDate(const Date &date) {
    Transporte::date = date;
}

/// Construtor
/// \cria um objeto da classe Transporte,
/// \com os valores default de distância = 9999, tipo = "autocarro", date e time
Transporte::Transporte(){
    distancia = 9999;
    tipo = "autocarro";
}
