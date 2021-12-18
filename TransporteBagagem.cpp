//
// Created by PC on 14/12/2021.
//

#include "TransporteBagagem.h"
/// Default constructor
TransporteBagagem::TransporteBagagem() {}
/// Constructor
/// \param c número de carruagens do carrinho
/// \param n número de pilhas por carruagem
/// \param m número de malas por pilha
TransporteBagagem::TransporteBagagem(int c, int n, int m) {
    this->c = c;
    this->n = n;
    this->m = m;
}
/// Getter
/// \return retorna o número de carruagens do carrinho
int TransporteBagagem::getC() const {
    return c;
}
/// Setter
/// \param c dá um novo valor ao número de carruagens
void TransporteBagagem::setC(int c) {
    this->c = c;
}
/// Getter
/// \return retorna o número de pilhas por carruagem
int TransporteBagagem::getN() const {
    return n;
}
/// Setter
/// \param n dá um novo valor ao número de pilhas por carruagem
void TransporteBagagem::setN(int n) {
    this->n = n;
}
/// Getter
/// \return retorna o número de malas por pilha
int TransporteBagagem::getM() const {
    return m;
}
/// Setter
/// \param m dá um novo valor ao número de malas por pilha
void TransporteBagagem::setM(int m) {
    this->m = m;
}
/// Adiciona a bagagem ao tapete
void TransporteBagagem::addBagagemTapete(Bagagem bagagem) {
    tapete.push(bagagem);
}
/// Adiciona as bagagens no tapete ao carrinho que as irá transportar, retorna false se não houver espaço suficiente, caso contrário retorna true
bool TransporteBagagem::addBagagensCarrinho() {
    stack<Bagagem> aux;
    vector<stack<Bagagem>> auxv;
    if (tapete.size() > c*n*m) {
        return false;
    }
    while (!tapete.empty()) {
        while (auxv.size() < n) {
            while(aux.size() < m) {
                aux.push(tapete.front());
                tapete.pop();
            }
            auxv.push_back(aux);
            while(!aux.empty()) {
                aux.pop();
            }
        }
        carrinho.push_back(auxv);
        auxv.clear();
    }
    return true;
}