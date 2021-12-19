//
// Created by PC on 28/11/2021.
//

#include <string>
#include "Voo.h"
/// Default Constructor
Voo::Voo(){
    this->numVoo = 0;
    this->duracaoVoo = 0;
}
/// Constructor
/// \param numVoo número de identificação do voo
/// \param dataPartida data de partida do voo
/// \param duracaoVoo duração do voo em horas
/// \param passageiros lista dos passageiros que estão no voo
/// \param transporteBagagem o transporte da bagagem (tapete e carrinho)
Voo::Voo(int numVoo, Date dataPartida, float duracaoVoo, list<Passageiro> passageiros, TransporteBagagem transporteBagagem){
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracaoVoo = duracaoVoo;
    this->passageiros = passageiros;
    this->transporteBagagem = transporteBagagem;
}
bool const Voo::operator < (Voo v2) const {
    return numVoo < v2.getNum();
}
/// Getter
/// \return retorna o número de identificação do voo
int Voo::getNum() const{
    return numVoo;
}
/// Getter
/// \return retorna a data de partida do voo
Date Voo::getData() const {
    return dataPartida;
}
/// Getter
/// \return retorna a duracao do voo
float Voo::getDuracao() const {
    return duracaoVoo;
}
/// Getter
/// \return retorna a lista de passageiros do voo
list<Passageiro> Voo::getPassageiros() const {
    return passageiros;
}
/// Setter
/// \param num passa a ser o novo número identificador do voo
void Voo::setNum(int num) {
    numVoo = num;
}
/// Setter
/// \param data passa a ser a nova data de partida do voo
void Voo::setData(Date data) {
    dataPartida = data;
}
/// Setter
/// \param dur passa a ser a nova duração do voo
void Voo::setDuracao(int dur){
    duracaoVoo = dur;
}
/// Adiciona um passageiro à lista de passageiros
/// \param passageiro novo passageiro a ser adicionado ao voo
void Voo::addPassageiro(Passageiro &passageiro) {
    passageiros.push_back(passageiro);
}

void Voo::addListaPassageiro(list<Passageiro> passageiros) {
    for (Passageiro pass : passageiros) {
        addPassageiro(pass);
    }
}
/// Remove um passageiro do voo
/// \param passageiro a ser removido
/// \return true se o passageiro estivesse presente no voo, false no caso contrário
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
void Voo::setPassageiros(list<Passageiro> passageiros) {
    this->passageiros = passageiros;
}

void Voo::setTB(TransporteBagagem t) {
    this->transporteBagagem = t;
}
/// Guarda o voo no devido ficheiro e adiciona-o ao ficheiro de todos os voos (voo_all_save.txt)
/// \return true se foi possível abrir o ficheiro, caso contrário false
bool Voo::saveFile() {
    ofstream save_all;

    save_all.open("voo_all_save.txt", ios_base::app);
    save_all << numVoo << endl;;
    save_all.close();

    ofstream save_stream;
    save_stream.open("voo_"+ to_string(this->numVoo) + "_save.txt");
    if(save_stream.is_open()){

        save_stream << numVoo << " " << dataPartida.getDay() << " " << dataPartida.getMonth() << " " << dataPartida.getYear() << " " << duracaoVoo << " " << passageiros.size() << endl;
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
/// Lê um objeto do tipo voo de um ficheiro e preenche-o com todos os atributos
/// \return true se o ficheiro pretendido existir, caso contrário false
bool Voo::loadFile() {
    int c, n , m, id, numBilhetes, numBagagens, day, month, year, numPass;
    string nome;
    ifstream load_stream;
    load_stream.open("voo_"+ to_string(this->numVoo) + "_save.txt");
    if(load_stream.is_open()){
        load_stream >> this->numVoo >> day >> month >> year >> this->duracaoVoo >> numPass;
        this->dataPartida = Date(day, month, year);
        load_stream >> c >> n >> m;
        this->transporteBagagem = TransporteBagagem(c, n, m);
        for (size_t i = 0; i < numPass; i++){
            vector<Bilhete> bilhetes;
            vector<Bagagem> bagagens;
            load_stream >> id >> nome >> numBilhetes >> numBagagens;
            for (size_t i = 0; i < numBilhetes; i++) {
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
            this->passageiros.push_back(passageiro);
        }
        load_stream.close();
        return true;
    }
    else return false;
}
