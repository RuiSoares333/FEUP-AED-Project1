//
// Created by PC on 13/12/2021.
//

#include "Bilhete.h"
/// Default constructor
Bilhete::Bilhete() {
    this->num = 0;
    this->check_bagagem = false;
    this->checkin = false;
}
/// Constructor
/// \param num número do lugar do bilhete
/// \param check_bagagem true se tiver bagagem, falso se nao
/// \param checkin true se for check-in automatico, caso contrario false
Bilhete::Bilhete(int num, bool check_bagagem, bool checkin) {
    this->num = num;
    this->check_bagagem = check_bagagem;
    this->checkin = checkin;
}
/// Getter
/// \return retorna o número de identificação do bilhete
int Bilhete::getNum() const {
    return num;
}
/// Setter
/// \param num altera o valor do número de identificação do bilhete
void Bilhete::setNum(int num) {
    this->num = num;
}
/// Getter
/// \return retorna true se tem bagagem, false se nao
bool Bilhete::checkBagagem() const {
    return check_bagagem;
}
/// Setter
/// \param check altera o valor de check_bagagem para check
void Bilhete::setCheckBagagem(bool check) {
    this->check_bagagem = check;
}
/// Getter
/// \return
bool Bilhete::getCheckin() const {
    return checkin;
}
/// Setter
/// \param checkin altera o valor de checkin para checkin
void Bilhete::setCheckin(bool checkin) {
    this->checkin = checkin;
}
