//
// Created by ASUS on 18/12/2021.
//

#include <fstream>
#include <algorithm>
#include "BaseDados.h"

void BaseDados::loadAll() {
    loadServicos();
    loadAirports();
    loadVoos();
    loadAvioes();
}

void BaseDados::saveAll() {
    saveServicos();
    saveAirports();
    saveVoos();
    saveAvioes();
}

void BaseDados::sortServicos() {
    servicos.sort();
}

void BaseDados::sortAvioes() {
    avioes.sort();
}

void BaseDados::sortVoos() {
    voos.sort();
}

void BaseDados::transportDraw(Aeroporto &aeroporto) {
    list<Aeroporto>::iterator ite;
    for (ite = aeroportos.begin(); ite != aeroportos.end(); ite++) {
        if ((*ite) == aeroporto) {
            aeroporto.setTransportes((*ite).getTransportes());
        }
    }
    BST<Transporte> transportes = aeroporto.getTransportes();
    BSTItrIn<Transporte> it(transportes);
    int spaces = 20;
    cout << setfill(' ') << setw(spaces) << "DD/MM/YYYY" << setfill(' ') << setw(spaces) << "HH:MM" << setfill(' ')
         << setw(spaces) << "Distancia(m)" << setfill(' ') << setw(spaces) << "Tipo" << endl;
    cout << string(4 * spaces, '=') << endl;

    while (!(it.isAtEnd())) {
        int distancia = it.retrieve().getDistancia();
        string tipo = it.retrieve().getTipo();
        int day = it.retrieve().getDate().getDay();
        int month = it.retrieve().getDate().getMonth();
        int year = it.retrieve().getDate().getYear();
        int hora = it.retrieve().getTime().getHora();
        int minuto = it.retrieve().getTime().getMinuto();

        string day_s = to_string(day);
        string month_s = to_string(month);

        string date =
                string(2 - day_s.length(), '0') + day_s + "/" + string(2 - month_s.length(), '0') + month_s + "/" +
                to_string(year);

        string hora_s = to_string(hora);
        string minuto_s = to_string(minuto);
        string time = string(2 - hora_s.length(), '0') + hora_s + ":" + string(2 - minuto_s.length(), '0') + minuto_s;
        cout << setfill(' ') << setw(spaces) << date << setfill(' ') << setw(spaces) << time << setfill(' ')
             << setw(spaces) << distancia << setfill(' ') << setw(spaces) << tipo << endl;
        it.advance();
    }
}


void BaseDados::drawAvioes(list<Aviao> lista) const {
    int spaces = 30;
    cout << setfill(' ') << setw(spaces) << "Matricula" << setfill(' ') << setw(spaces) << "Capacidade"  << setfill(' ') << setw(spaces) << "Voos"  << setfill(' ') << setw(spaces) << "S. Agendados"  << endl;
    cout << string(4 * spaces, '=') << endl;
    for (Aviao a : lista) {
        cout << setfill(' ') << setw(spaces) << a.getMatricula() << setfill(' ') << setw(spaces) << a.getCapacidade() << setfill(' ') << setw(spaces) << a.getPlanoVoo().size()<< setfill(' ') << setw(spaces) << a.getServicosAgendados().size() << endl;
    }
}

bool sortAvioesCap(Aviao &a1, Aviao &a2){
    if(a1.getCapacidade() == a2.getCapacidade()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getCapacidade() < a2.getCapacidade();
}

void BaseDados::drawAvioesCap() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesCap);
    drawAvioes(auxlist);
}

bool sortAvioesVoo(Aviao &a1, Aviao &a2){
    if(a1.getPlanoVoo().size() == a2.getPlanoVoo().size()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getPlanoVoo().size() < a2.getPlanoVoo().size();
}

void BaseDados::drawAvioesVoo() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesVoo);
    drawAvioes(auxlist);
}

bool sortAvioesSerAg(Aviao &a1, Aviao &a2){
    if(a1.getServicosAgendados().size() == a2.getServicosAgendados().size()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getServicosAgendados().size() < a2.getServicosAgendados().size();
}

void BaseDados::drawAvioesSerAg() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesSerAg);
    drawAvioes(auxlist);
}

bool sortAvioesSerTer(Aviao &a1, Aviao &a2){
    if(a1.getServicosFeitos().size() == a2.getServicosFeitos().size()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getServicosFeitos().size() < a2.getServicosFeitos().size();
}

void BaseDados::drawAvioesSerTer() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesSerTer);
    drawAvioes(auxlist);
}

void BaseDados::drawVoos(list<Voo> auxVoos) const {
    int spaces = 30;
    cout << setfill(' ') << setw(spaces) << "Numero do Voo" << setfill(' ') << setw(spaces) << "Data de partida" << setfill(' ') << setw(spaces) << "Duracao do voo" << endl;
    cout << string (3*spaces, '=') << endl;
    for (Voo v : auxVoos) {
        string day_s = to_string(v.getData().getDay());
        string month_s = to_string(v.getData().getMonth());
        string date = string(2-day_s.length(), '0') + day_s + "/" + string(2-month_s.length(), '0') + month_s +"/" + to_string(v.getData().getYear());
        cout << setfill(' ') << setw(spaces) << v.getNum() << setfill(' ') << setw(spaces) << date << setfill(' ') << setw(spaces) << v.getDuracao() << endl;
    }
}

//bool sortVoosData(Voo &v1, Voo &v2) {
//    list<Voo> auxlist = voos;
//}

void BaseDados::drawVoosData() const {

}

bool BaseDados::loadAirports(){
    string nome, cidade, pais;
    ifstream loadStream;
    loadStream.open("aeroporto_all_save.txt");
    if(loadStream.is_open()){
        while(loadStream >> nome >> cidade >> pais){
            Aeroporto  aero(nome, pais, cidade);
            aero.loadFile();

            aeroportos.push_back(aero);
        }
        loadStream.close();
        return true;
    }
    return false;
}

bool BaseDados::saveAirports(){
    ofstream saveStream;
    saveStream.open("aeroporto_all_save.txt", ofstream ::trunc);
    if(saveStream.is_open()){
        for(Aeroporto aeroporto: aeroportos){
            aeroporto.saveFile();
        }
        saveStream.close();
        return true;
    }
    return false;
}

void BaseDados::loadServicos(){
    ifstream loadStream;
    loadStream.open("servicos_all_save.txt");

    int id, y, m, d, numServ;
    string funcionario, tipo;

    if (loadStream.is_open()) {
        loadStream >> numServ;
        for (size_t i = 0; i < numServ; i++){
            loadStream >> id >> funcionario >> tipo >> y >> m >> d;
            Date data(y, m, d);
            servico s(id, tipo, funcionario, data);
            servicos.push_back(s);
        }
    }
    loadStream.close();
}

void BaseDados::saveServicos() {
    ofstream save_all;

    save_all.open("servicos_all_save.txt", ios_base::trunc);
    save_all << servicos.size() << endl;
    if (save_all.is_open()) {
        for(auto ser : servicos){
            save_all << ser.getID() << " " << ser.getFuncionario() << " " << ser.getTipo() << " " <<  ser.getData().getYear() << " " << ser.getData().getMonth() << " " << ser.getData().getDay() << endl;
        }
    }

    save_all.close();
}

void BaseDados::loadAvioes() {
    ifstream loadStream;
    loadStream.open("avioes_all_save.txt");

    int numAvioes;
    loadStream >> numAvioes;
    if (loadStream.is_open()) {
        for(int i = 0; i< numAvioes; i++){
            string matr; int cap, numVoos, numSerAg, numSerFei;
            loadStream >> matr >> cap >> numVoos >> numSerAg >> numSerFei;
            Aviao a = Aviao(matr, cap);

            for(int count = 0; count<numVoos; count++){
                int idVoo;
                loadStream >> idVoo;
                for(auto v : voos){
                    if(v.getNum() == idVoo) a.adicionarVoo(v);
                }
            }

            for(int count = 0; count<numSerAg; count++){
                int idSer;
                loadStream >> idSer;
                for(auto s : servicos){
                    if(s.getID() == idSer) a.addServAgendado(s);
                }
            }

            for(int count = 0; count<numSerFei; count++){
                int idSer;
                loadStream >> idSer;
                for(auto s : servicos){
                    if(s.getID() == idSer) a.addServCompleto(s);
                }
            }
            avioes.push_back(a);
        }
    }
    loadStream.close();
}


void BaseDados::saveAvioes(){
    ofstream save_all;

    save_all.open("avioes_all_save.txt");
    save_all << avioes.size() << endl;

    if (save_all.is_open()) {
        for(auto av : avioes){
            save_all << av.getMatricula() << " " << av.getCapacidade() << " " << av.getPlanoVoo().size() << " " << av.getServicosAgendados().size() << " " << av.getServicosFeitos().size() << endl;
            for(auto voo : av.getPlanoVoo()){
                save_all << voo.getNum() << endl;
            }
            for (servico s : av.getServicosAgendados()) {
                save_all << s.getID() << endl;
            }
            for(auto ser : av.getServicosFeitos()){
                save_all << ser.getID() << endl;
            }
        }
    }

    save_all.close();
}

bool BaseDados::loadVoos() {
    int numVoo;
    ifstream load;
    load.open("voo_all_save.txt");
    if (load.is_open()) {
        while (load >> numVoo) {
            Voo voo;
            voo.setNum(numVoo);
            voo.loadFile();
            voos.push_back(voo);
        }
        load.close();
        return true;
    }
    load.close();
    return false;
}

bool BaseDados::saveVoos() {
    ofstream save;
    save.open("voo_all_save.txt", ofstream::trunc);
    if (save.is_open()) {
        for (Voo voo : voos) {
            voo.saveFile();
        }
        save.close();
        return true;
    }
    return false;
}

list<Aeroporto> BaseDados::getAeroportos() const {
    return aeroportos;
}

list<servico> BaseDados::getServicos() const {
    return servicos;
}

list<Aviao> BaseDados::getAvioes() const {
    return avioes;
}

list<Voo> BaseDados::getVoos() const {
    return voos;
}

void BaseDados::airportSort() {
    aeroportos.sort();
}

void BaseDados::airportDraw() {
    airportSort();
    int spaces = 30;
    cout <<setfill(' ') << setw(spaces) << "Nome" << setfill(' ') << setw(spaces) << "Cidade" << setfill(' ') << setw(spaces) << "Pais" << endl;
    cout << string(3 * spaces, '=') << endl;
    for(Aeroporto aeroporto: aeroportos){
        cout << setfill(' ') << setw(spaces) << aeroporto.getNome() << setfill(' ') << setw(spaces) << aeroporto.getCidade() << setfill(' ') << setw(spaces) << aeroporto.getPais() << endl;
    }
}

void BaseDados::addAirport(Aeroporto aeroporto) {
    aeroportos.push_back(aeroporto);
    airportSort();
}

bool BaseDados::removeAirport(Aeroporto aeroporto) { //remove a primeria instancia desse aeroporto
    list<Aeroporto>::iterator it;
    for(it = aeroportos.begin(); it != aeroportos.end(); it++){
        if((*it)==aeroporto){
            aeroportos.erase(it);
            return true;
        }
    }
    return false;
}

bool BaseDados::addTransporte(Aeroporto aeroporto, Transporte trans){
    list<Aeroporto>::iterator it;
    for(it = aeroportos.begin(); it != aeroportos.end(); it++){
        if((*it)==aeroporto){
            bool check = (*it).insertTransporte(trans);
            return check;
        }
    }
    return false;
}

bool BaseDados::removeTransporte(Aeroporto &aeroporto, Transporte transporte) {
    list<Aeroporto>::iterator it;
    for (it = aeroportos.begin(); it != aeroportos.end(); it++){
        if((*it) == aeroporto){
            bool check = (*it).removeTransporte(transporte);
            return check;
        }
    }
    return false;
}

void BaseDados::addVoo(Voo v) {
    voos.push_back(v);
    sortVoos();
}

bool BaseDados::removeVoo(int numVoo) {
    list<Voo>::iterator it;
    for (it = voos.begin(); it != voos.end(); it ++) {
        if (it->getNum() == numVoo) {
            voos.erase(it);
            return true;
        }
    }
    return false;
}

void BaseDados::addAviao(Aviao a) {
    avioes.push_back(a);
    sortAvioes();
}

void BaseDados::removeAviao(string matricula) {
    list<Aviao>::iterator it;
    for (it = avioes.begin(); it != avioes.end(); it ++) {
        if (it->getMatricula() == matricula) {
            avioes.erase(it);
            break;
        }
    }
}

void BaseDados::addServico(servico s) {
    servicos.push_back(s);
    sortServicos();
}

bool BaseDados::updateAviaoVoo(string matricula, Voo voo) {
    for(auto av : avioes){
        if(av.getMatricula() == matricula){
            av.adicionarVoo(voo);
            return true;
        }
    }
    return false;
}

bool BaseDados::updateAviaoServicoCriar(string matricula, servico ser) {
    for(auto av: avioes){
        if(av.getMatricula() == matricula){
            av.addServAgendado(ser);
            return true;
        }
    }
    return false;
}

bool BaseDados::updateAviaoServicoTerminar(string matricula) {
    list<Aviao>::iterator iter;
    for (iter = avioes.begin(); iter != avioes.end(); iter++) {
        if (iter->getMatricula() == matricula) {
            iter->terminarServico();
            return true;
        }
    }
    return false;
}

bool BaseDados::updateVoo(int numVoo_s, int numVoo_p, Date data, float duracao, TransporteBagagem t) {
    list<Voo>::iterator iter;
    for (iter = voos.begin(); iter != voos.end(); iter++) {
        if (iter->getNum() == numVoo_s) {
            list<Passageiro> passageiros = iter->getPassageiros();
            voos.erase(iter);
            Voo v1(numVoo_p, data, duracao, passageiros, t);
            voos.push_back(v1);
            voos.sort();
            return true;
        }
    }
    return false;
}

bool BaseDados::updateAirport(Aeroporto aeroporto, string nome, string cidade, string pais) {
    list<Aeroporto>::iterator it;
    for(it = aeroportos.begin(); it!= aeroportos.end(); it++){
        if(*it == aeroporto){
            if(nome != "-") (*it).setNome(nome);
            if(cidade != "-") (*it).setCidade(cidade);
            if(pais != "-") (*it).setPais(pais);
            return true;
        }
    }
    return false;
}

bool BaseDados::updateTransporte(Aeroporto aeroporto, Transporte transporte, int distancia, string tipo, Time time,
                                 Date date) {
    /*
    for(Aeroporto aero: aeroportos){
        if(aero == aeroporto){
            aero.removeTransporte(transporte);
            transporte.setTipo(tipo);
            transporte.setDate(date);
            transporte.setDistancia(distancia);
            transporte.setTime(time);
            aero.insertTransporte(transporte);
        }
    }
     */
    list<Aeroporto>::iterator it;
    for(it = aeroportos.begin(); it!= aeroportos.end(); it++){
        if(*it == aeroporto){
            (*it).removeTransporte(transporte);
            transporte.setTipo(tipo);
            transporte.setDate(date);
            transporte.setTime(time);
            transporte.setDistancia(distancia);
            (*it).insertTransporte(transporte);
            return true;
        }
    }

    return false;
}
