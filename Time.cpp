#include "Time.h"

/// Construtor
/// \cria um objeto da classe Time,
/// \com valores default hora = 0 e minuto = 0
Time::Time(){
    hora = 00;
    minuto = 00;
}

/// Construtor
/// \param hora
/// \param minuto
/// \se hora > 23 dá a exceção "hora > 23"
/// \se hora < 0 dá a exceção "hora < 0"
/// \se minuto > 59 dá a exceção "minuto > 59"
/// \se minuto < 0 dá a exceção "minuto < "
/// \cria um objeto da classe Time com os atributos hora e minuto
Time::Time(int hora, int minuto) {
    if (hora > 23) throw "hora > 23";
    if (hora < 0) throw "hora < 0";
    if(minuto > 59) throw "minuto > 59";
    if(minuto < 0) throw "minuto < 0";
    this -> hora = hora;
    this-> minuto = minuto;
}

/// Setter
/// \param hora
/// \muda a hora do time
void Time::setHora(int hora) {
    this -> hora = hora;
}

/// Setter
/// \param int minuto
/// \muda minuto do time
void Time::setMinuto(int minuto) {
    this -> minuto = minuto;
}

/// Getter
/// \param hora
/// \muda o minuto do time
int Time::getHora() const{
    return hora;
}

/// Getter
/// \param minuto
/// \muda o minuto do time
int Time::getMinuto() const{
    return minuto;
}

/// Operator<
/// \se as horas forem iguais retorna minuto < t2.getMinuto()
/// \caso contrário retorna hora < t2.getHora()
bool const Time::operator<(const Time t2) const {
    if(hora == t2.getHora()){
        return minuto < t2.getMinuto();
    }
    return hora < t2.getHora();
}

/// Operator
/// Operador "==" que diz se 2 Tempos são iguais
bool const Time::operator==(const Time t2) const{
    return hora == t2.getHora() && minuto == t2.getMinuto();
}
