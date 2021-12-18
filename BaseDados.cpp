//
// Created by ASUS on 18/12/2021.
//

#include <fstream>
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

const list<Aeroporto> &BaseDados::getAeroportos() const {
    return aeroportos;
}

const list<servico> &BaseDados::getServicos() const {
    return servicos;
}

const list<Aviao> &BaseDados::getAvioes() const {
    return avioes;
}

const list<Voo> &BaseDados::getVoos() const {
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
