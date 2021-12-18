//
// Created by PC on 28/11/2021.
//

#include <string>
#include "Voo.h"

Voo::Voo(){
    this->numVoo = 0;
    this->duracaoVoo = 0;
}

Voo::Voo(int numVoo, Date dataPartida, int duracaoVoo, list<Passageiro> passageiros, TransporteBagagem transporteBagagem){
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracaoVoo = duracaoVoo;
    this->passageiros = passageiros;
    this->transporteBagagem = transporteBagagem;
}
int Voo::getNum() const{
    return numVoo;
}
Date Voo::getData() const {
    return dataPartida;
}
int Voo::getDuracao() const {
    return duracaoVoo;
}
list<Passageiro> Voo::getPassageiros() const {
    return passageiros;
}
void Voo::setNum(int num) {
    numVoo = num;
}
void Voo::setData(Date data) {
    dataPartida = data;
}
void Voo::setDuracao(int dur){
    duracaoVoo = dur;
}

bool Voo::addPassageiro(Passageiro& passageiro) {
    passageiros.push_back(passageiro);
    return true;
}

bool Voo::removePassageiro(Passageiro& passageiro) {
    list<Passageiro>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); it++) {
        if (it->getId() == passageiro.getId()) {
            passageiros.erase(it);
            return true;
        }
    }
    return false;
}

bool Voo::saveFile() {
    ofstream save_all;

    save_all.open("voos_all_save.txt", ios_base::app);
    save_all << numVoo << endl;;
    save_all.close();

    ofstream save_stream;
    save_stream.open("voo_"+ to_string(this->numVoo) + "_save.txt");
    if(save_stream.is_open()){

        save_stream << numVoo << " " << dataPartida.getDay() << " " << dataPartida.getMonth() << " " << dataPartida.getYear() << " " << duracaoVoo << endl;
        save_stream << transporteBagagem.getC() << " " << transporteBagagem.getN() << " " << transporteBagagem.getM() << endl;

        for (Passageiro pass : passageiros) {
            save_stream << pass.getId() << " "<< pass.getNome() << " " <<pass.getBilhetes().size() << " " << pass.getBagagens().size() << endl;
            for (Bilhete bil : pass.getBilhetes()) {
                save_stream << bil.getNum() << " " << bil.getCheckin() << " " <<  bil.checkBagagem() << endl;
            }
            for (Bagagem bag : pass.getBagagens()) {
                save_stream << bag.getComprimento() << " " << bag.getLargura() << " " << bag.getAltura() << " " << bag.getPeso() << endl;
            }
        }
        save_stream.close();
        return true;
    }
    else return false;
}

bool Voo::loadFile() {
    int numVoo, duracaoVoo, c, n , m, id, numBilhete, numBagagens, day, month, year;
    string nome;
    Date dataPartida; //se houver classe data futuramente alterar
    list<Passageiro> passageiros;
    ifstream load_stream;
    load_stream.open("voo_"+ to_string(this->numVoo) + "_save.txt");
    if(load_stream.is_open()){
        load_stream >> numVoo >> day >> month >> year >> duracaoVoo;
        load_stream >> c >> n >> m;
        TransporteBagagem transporteBagagem(c, n, m);

        while(!load_stream.eof()){
            vector<Bilhete> bilhetes;
            vector<Bagagem> bagagens;
            load_stream >> id >> nome >> numBilhete >> numBagagens;
            for (size_t i = 0; i < numBilhete; i++) {
                int numBil;
                bool checkBagagem, checkin;
                load_stream >> numBil >> checkBagagem >> checkin;
                Bilhete bilhete(numBil, checkBagagem, checkin);
                bilhetes.push_back(bilhete);
            }
            for (size_t j = 0; j < numBagagens; j++) {
                float comprimento, largura, altura, peso;
                load_stream >> comprimento >> largura >> altura >> peso;
                Bagagem bagagem(comprimento, largura, altura, peso);
                bagagens.push_back(bagagem);
            }
            Passageiro passageiro(nome, id, bilhetes, bagagens);
            passageiros.push_back(passageiro);
        }
        this->numVoo = numVoo;
        this->dataPartida = Date(day, month, year);
        this->duracaoVoo = duracaoVoo;
        this->passageiros = passageiros;
        this->transporteBagagem = transporteBagagem;
        load_stream.close();
        return true;
    }
    else return false;
}