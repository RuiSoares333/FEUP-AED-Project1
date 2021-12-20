//
// Created by ASUS on 18/12/2021.
//

#include <fstream>
#include <algorithm>
#include "BaseDados.h"

/// Loader
/// Funcao que chama todas as outras funções que carregam as informações para a base de dados
void BaseDados::loadAll() {
    loadServicos();
    loadAirports();
    loadVoos();
    loadAvioes();
}

/// Saver
/// Função que chama todas as outras funções que guardam as infomações da base de dados nos ficheiros
void BaseDados::saveAll() {
    saveServicos();
    saveAirports();
    saveVoos();
    saveAvioes();
}

/// Sorter
/// Dá sort à lista que contem todos os servicos
void BaseDados::sortServicos() {
    servicos.sort();
}

/// Sorter
/// Dá sort à lista que contem todos os avioes
void BaseDados::sortAvioes() {
    avioes.sort();
}

/// Sorter
/// Dá sort à lista que contem todos os voos
void BaseDados::sortVoos() {
    voos.sort();
}

/// Sorter
/// Dá sort à lista que contem todos os transportes pela distancia
bool sortTransporteDis(const Transporte &t1, const Transporte &t2);

/// Sorter
/// Dá sort à lista que contem todos os servicos pelo tipo
bool sortTransporteTipo(const Transporte &t1, const Transporte &t2);

/// Drawer
/// Imprime todos os \param transportes de um \param aeroporto
void BaseDados::transportDraw(Aeroporto &aeroporto) {
    int input;
    cout << "Como quer ordenar os transportes? \n1. Data \n2. Distancia \n3. Tipo" << endl;
    while(true){
        cin >> input;
        if(input == 1 || input == 2 || input == 3) break;
        else cout << "Por favor insira 1, 2 ou 3" << endl;
    }

    list<Aeroporto>::iterator ite;
    for (ite = aeroportos.begin(); ite != aeroportos.end(); ite++) {
        if ((*ite) == aeroporto) {
            aeroporto.setTransportes((*ite).getTransportes());
        }
    }
    BST<Transporte> transportes = aeroporto.getTransportes();
    BSTItrIn<Transporte> it(transportes);

    list<Transporte> l_tra;
    list<Transporte>::iterator iter;

    int spaces = 20;
    cout << setfill(' ') << setw(spaces) << "DD/MM/YYYY" << setfill(' ') << setw(spaces) << "HH:MM" << setfill(' ')
         << setw(spaces) << "Distancia(m)" << setfill(' ') << setw(spaces) << "Tipo" << endl;
    cout << string(4 * spaces, '=') << endl;

    while (!(it.isAtEnd())) {
        l_tra.push_back(it.retrieve());
        it.advance();
    }
    l_tra.sort();
    if(input == 2) l_tra.sort(sortTransporteDis);
    if(input == 3) l_tra.sort(sortTransporteTipo);

    for(iter = l_tra.begin(); iter != l_tra.end(); iter++){
        int distancia = (*iter).getDistancia();
        string tipo = (*iter).getTipo();
        int day = (*iter).getDate().getDay();
        int month = (*iter).getDate().getMonth();
        int year = (*iter).getDate().getYear();
        int hora = (*iter).getTime().getHora();
        int minuto = (*iter).getTime().getMinuto();

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
    }
    /*
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
     */
}

/// Drawer
/// Desenha todos os \param transportes de um \param aeroporto entre \param d1 e \param d2
void BaseDados::transporteDrawParcial(Aeroporto &aeroporto, Date d1, Date d2, Time t1, Time t2){
    int input;
    cout << "Como quer ordenar os transportes? \n1. Data \n2. Distancia \n3. Tipo" << endl;
    while(true){
        cin >> input;
        if(input == 1 || input == 2 || input == 3) break;
        else cout << "Por favor insira 1, 2 ou 3" << endl;
    }

    list<Aeroporto>::iterator ite;
    for (ite = aeroportos.begin(); ite != aeroportos.end(); ite++) {
        if ((*ite) == aeroporto) {
            aeroporto.setTransportes((*ite).getTransportes());
        }
    }
    BST<Transporte> transportes = aeroporto.getTransportes();
    BSTItrIn<Transporte> it(transportes);

    list<Transporte> l_tra;
    list<Transporte>::iterator iter;

    int spaces = 20;
    cout << setfill(' ') << setw(spaces) << "DD/MM/YYYY" << setfill(' ') << setw(spaces) << "HH:MM" << setfill(' ')
         << setw(spaces) << "Distancia(m)" << setfill(' ') << setw(spaces) << "Tipo" << endl;
    cout << string(4 * spaces, '=') << endl;

    while (!(it.isAtEnd())) {
        if(d1 < it.retrieve().getDate()){
            if(it.retrieve().getDate() < d2){
                l_tra.push_back(it.retrieve());
            }
            else if(it.retrieve().getDate() == d2){
                if(it.retrieve().getTime() < t2 || it.retrieve().getTime() == t2) l_tra.push_back(it.retrieve());
            }
        }
        else if (d1 == it.retrieve().getDate()){
            if(t1 < it.retrieve().getTime() || t1 == it.retrieve().getTime()){
                if(it.retrieve().getDate() < d2){
                    l_tra.push_back(it.retrieve());
                }
                else if(it.retrieve().getDate() == d2){
                    if(it.retrieve().getTime() < t2 || it.retrieve().getTime() == t2) l_tra.push_back(it.retrieve());
                }
            }
        }
        it.advance();
    }
    l_tra.sort();
    if(input == 2) l_tra.sort(sortTransporteDis);
    if(input == 3) l_tra.sort(sortTransporteTipo);

    for(iter = l_tra.begin(); iter != l_tra.end(); iter++){
        int distancia = (*iter).getDistancia();
        string tipo = (*iter).getTipo();
        int day = (*iter).getDate().getDay();
        int month = (*iter).getDate().getMonth();
        int year = (*iter).getDate().getYear();
        int hora = (*iter).getTime().getHora();
        int minuto = (*iter).getTime().getMinuto();

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
    }
}


/// Drawer
/// Imprime todos os avioes no sistema com uma dada ordenação numa \param lista
void BaseDados::drawAvioes(list<Aviao> lista) const {
    int spaces = 30;
    cout << setfill(' ') << setw(spaces) << "Matricula" << setfill(' ') << setw(spaces) << "Capacidade"  << setfill(' ') << setw(spaces) << "Voos"  << setfill(' ') << setw(spaces) << "S. Agendados"  << endl;
    cout << string(4 * spaces, '=') << endl;
    for (Aviao a : lista) {
        cout << setfill(' ') << setw(spaces) << a.getMatricula() << setfill(' ') << setw(spaces) << a.getCapacidade() << setfill(' ') << setw(spaces) << a.getPlanoVoo().size()<< setfill(' ') << setw(spaces) << a.getServicosAgendados().size() << endl;
    }
}

/// Sorter
/// Ordena todos os Aeroportos pelo nome
bool sortAeroportoNome(const Aeroporto &a1, const Aeroporto &a2){
    if(a1.getNome() == a2.getNome()){
        if(a1.getPais() == a2.getPais()){
            return a1.getCidade() < a2.getCidade();
        }
        else return a1.getPais() < a2.getPais();
    }
    else return a1.getNome() < a2.getNome();
}

/// Sorter
/// Ordena todos os Transportes por ordem crescente de distancia
bool sortTransporteDis(const Transporte &t1, const Transporte &t2){
    if(t1.getDistancia() == t2.getDistancia()){
        if(t1.getDate() == t2.getDate()) return t1.getTime() < t2.getTime();
        return t1.getDate() < t2.getDate();
    }
    else return t1.getDistancia() < t2.getDistancia();
}

/// Sorter
/// Ordena todos os Transportes de acordo com o Tipo
bool sortTransporteTipo(const Transporte &t1, const Transporte &t2){
    if(t1.getTipo() == t2.getTipo()){
        if(t1.getDate() == t2.getDate()) return t1.getTime() < t2.getTime();
        return t1.getDate() < t2.getDate();
    }
    else return t1.getTipo() < t2.getTipo();
}

/// Sorter
/// Ordena todos os Aviões por ordem crescente de capacidade
bool sortAvioesCap(Aviao &a1, Aviao &a2){
    if(a1.getCapacidade() == a2.getCapacidade()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getCapacidade() < a2.getCapacidade();
}

/// Drawer
/// Imprime todos os Aviões ordenados por ordem crescente de capacidade
void BaseDados::drawAvioesCap() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesCap);
    drawAvioes(auxlist);
}


/// Sorter
/// Ordena todos os Avioes por ordem crescente de número de voos agendados
bool sortAvioesVoo(Aviao &a1, Aviao &a2){
    if(a1.getPlanoVoo().size() == a2.getPlanoVoo().size()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getPlanoVoo().size() < a2.getPlanoVoo().size();
}

/// Drawer
/// Desenha todos Avioes por ordem crescente de número de voos agendados
void BaseDados::drawAvioesVoo() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesVoo);
    drawAvioes(auxlist);
}

/// Sorter
/// Ordena todos os Avioes de acordo com o número de Serviços Agendados
bool sortAvioesSerAg(Aviao &a1, Aviao &a2){
    if(a1.getServicosAgendados().size() == a2.getServicosAgendados().size()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getServicosAgendados().size() < a2.getServicosAgendados().size();
}

/// Drawer
/// Imprime todos os Avioes de acordo com o número de Serviços Agendados
void BaseDados::drawAvioesSerAg() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesSerAg);
    drawAvioes(auxlist);
}

/// Sorter
/// Ordena todos os Avioes de acordo com o número de Serviços Terminados
bool sortAvioesSerTer(Aviao &a1, Aviao &a2){
    if(a1.getServicosFeitos().size() == a2.getServicosFeitos().size()){
        return a1.getMatricula() < a2.getMatricula();
    }
    return a1.getServicosFeitos().size() < a2.getServicosFeitos().size();
}

/// Drawer
/// Imprime todos os Avioes de acordo com o número de Serviços Terminados
void BaseDados::drawAvioesSerTer() const{
    list<Aviao> auxlist = avioes;
    auxlist.sort(sortAvioesSerTer);
    drawAvioes(auxlist);
}

/// Drawer
/// Imprime todos os Voos numa lista ordenada \param auxVoos
void BaseDados::drawVoos(list<Voo> auxVoos) const {
    int spaces = 20;
    cout << setfill(' ') << setw(spaces) << "Numero do Voo" << setfill(' ') << setw(spaces) << "Data de partida" << setfill(' ') << setw(spaces) << "Duracao do voo" << setfill(' ') << setw(spaces) << "Origem" << setfill(' ') << setw(spaces) << "Destino" << endl;
    cout << string (5*spaces, '=') << endl;
    for (Voo v : auxVoos) {
        string day_s = to_string(v.getData().getDay());
        string month_s = to_string(v.getData().getMonth());
        string date = string(2-day_s.length(), '0') + day_s + "/" + string(2-month_s.length(), '0') + month_s +"/" + to_string(v.getData().getYear());
        cout << setfill(' ') << setw(spaces) << v.getNum() << setfill(' ') << setw(spaces) << date << setfill(' ') << setw(spaces) << v.getDuracao() << setfill(' ') << setw(spaces) << v.getOrigem().getNome() << setfill(' ') << setw(spaces) <<v.getDestino().getNome() << endl;
    }
}

/// Sorter
/// Ordena Todos os Voos por ordem crescente de Data
bool sortVoosData(Voo &v1, Voo &v2) {
    return v1.getData() < v2.getData();
}

/// Drawer
/// Imprime Todos os Voos por ordem crescente de Data
void BaseDados::drawVoosData() const {
    list<Voo> auxlist = voos;
    auxlist.sort(sortVoosData);
    drawVoos(auxlist);
}

/// Sorter
/// Ordena Todos os Voos por ordem crescente de duracao
bool sortVoosDuracao(Voo &v1, Voo &v2) {
    return v1.getDuracao() < v2.getDuracao();
}

/// Drawer
/// Imprime Todos os Voos por ordem crescente de duracao
void BaseDados::drawVoosDuracao() const {
    list<Voo> auxlist = voos;
    auxlist.sort(sortVoosDuracao);
    drawVoos(auxlist);
}

/// Sorter
/// Ordena Todos os Voos por ordem crescente de número de passageiros
bool sortVoosPassageiros(Voo &v1, Voo &v2) {
    return v1.getPassageiros().size() < v2.getPassageiros().size();
}

/// Drawer
/// Imprime Todos os Voos por ordem crescente de número de passageiros
void BaseDados::drawVoosPassageiros() const {
    list<Voo> auxlist = voos;
    auxlist.sort(sortVoosPassageiros);
    drawVoos(auxlist);
}

/// Drawer
/// Imprime Todos os Voos no intervalo entre duas Datas
void BaseDados::drawParcialVoosData(Date d1, Date d2) const {
    list<Voo> auxlist;
    for (Voo v : voos) {
        if (!(v.getData() < d1) && !(d2 < v.getData())) {
            auxlist.push_back(v);
        }
    }
    drawVoos(auxlist);
}

/// Loader
/// Carrega todos os Aeroportos para o Sistema
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

/// Saver
/// Guarda todos os Aeroportos para o ficheiro aeroporto_all_save.txt
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

/// Loader
/// Carrega todos os Serviços para o sistema
void BaseDados::loadServicos(){
    ifstream loadStream;
    loadStream.open("servicos_all_save.txt");

    int id, y, m, d, numServ;
    string funcionario, tipo;

    if (loadStream.is_open()) {
        loadStream >> numServ;
        for (size_t i = 0; i < numServ; i++){
            loadStream >> id >> funcionario >> tipo >> d >> m >> y;
            Date data(d, m, y);
            servico s(id, tipo, funcionario, data);
            servicos.push_back(s);
        }
    }
    loadStream.close();
}

/// Saver
/// Guarda todos os Servicos dentro do ficheiro servicos_all_save.txt
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

/// Loader
/// Carrega todos os Avioes para o sistema
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

/// Saver
/// Guarda todos os Avioes para o sistema
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

/// Loader
/// Carrega todos os Voos para o sistema
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

/// Saver
/// Guarda todos os Voos no ficheiro voo_all_save.txt
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

/// Getter
/// \return \param aeroportos
list<Aeroporto> BaseDados::getAeroportos() const {
    return aeroportos;
}

/// Getter
/// \return \param servicos
list<servico> BaseDados::getServicos() const {
    return servicos;
}

/// Getter
/// \return \param avioes
list<Aviao> BaseDados::getAvioes() const {
    return avioes;
}

/// Getter
/// \return \param voos
list<Voo> BaseDados::getVoos() const {
    return voos;
}

/// Sorter
/// Ordena todos os aeroportos
void BaseDados::airportSort() {
    aeroportos.sort();
}

/// Drawer
/// Imprime todos os Aeroportos
void BaseDados::airportDraw() {
    int input;
    cout << "Como quer ordenar os aeroportos? \n1. Localização \n2. Nome" << endl;
    while (true){
        cin >> input;
        if(input == 1 || input == 2) break;
        else cout << "Por favor escolha 1 ou 2" << endl;
    }

    if(input == 1) airportSort();
    if(input == 2) aeroportos.sort(sortAeroportoNome);

    int spaces = 30;
    cout <<setfill(' ') << setw(spaces) << "Nome" << setfill(' ') << setw(spaces) << "Cidade" << setfill(' ') << setw(spaces) << "Pais" << endl;
    cout << string(3 * spaces, '=') << endl;
    for(Aeroporto aeroporto: aeroportos){
        cout << setfill(' ') << setw(spaces) << aeroporto.getNome() << setfill(' ') << setw(spaces) << aeroporto.getCidade() << setfill(' ') << setw(spaces) << aeroporto.getPais() << endl;
    }
    aeroportos.sort();
}

/// Adder
/// Adiciona um \param aeroporto à lista \param aeroportos
void BaseDados::addAirport(Aeroporto aeroporto) {
    aeroportos.push_back(aeroporto);
    airportSort();
}

/// Remover
/// Remove o \param aeroporto da lista \param aeroportos
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

/// Adder
/// Adiciona um \param transporte a um \param aeroporto na lista \param aeroportos
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

/// Remover
/// Remove um \param transporte de um \param aeroporto na lista \param aeroportos
bool BaseDados::removeTransporte(Aeroporto &aeroporto, Transporte transporte) {
    list<Aeroporto>::iterator it;
    for (it = aeroportos.begin(); it != aeroportos.end(); it++){
        if((*it) == aeroporto){
            BST<Transporte> transportes = (*it).getTransportes();
            int count = 0;
            cout << "aqui 1" << endl;
            BSTItrIn<Transporte> ite(transportes);
            while(!ite.isAtEnd()){
                count++;
                cout << "count:" << count << endl;
                ite.advance();
            }
            cout << "aqui 2" << endl;
            if(count <= 1) return false;
            cout << "aqui 3" << endl;
            bool check = (*it).removeTransporte(transporte);
            return check;
        }
    }
    return false;
}

/// Adder
/// Adiciona um \param voo à lista \param voos
void BaseDados::addVoo(Voo v) {
    voos.push_back(v);
    sortVoos();
}

/// Remover
/// Remove um \param Voo de acordo com o seu id(\param numVoo)
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

/// Adder
/// Adiciona um \param aviao à lista de Aviões
void BaseDados::addAviao(Aviao a) {
    avioes.push_back(a);
    sortAvioes();
}

/// Remover
/// Remove um \param aviao da lista \param avioes de acordo com a sua \param matricula
void BaseDados::removeAviao(string matricula) {
    list<Aviao>::iterator it;
    for (it = avioes.begin(); it != avioes.end(); it ++) {
        if (it->getMatricula() == matricula) {
            avioes.erase(it);
            break;
        }
    }
}

/// Adder
/// Adiciona um \param servico à lista \param servicos
void BaseDados::addServico(servico s) {
    servicos.push_back(s);
    sortServicos();
}

/// Adder
/// Adiciona um \param voo a um \param aviao na lista \param avioes de acordo com a sua \param matricula
bool BaseDados::updateAviaoVoo(string matricula, Voo voo) {
    for(auto av : avioes){
        if(av.getMatricula() == matricula){
            av.adicionarVoo(voo);
            return true;
        }
    }
    return false;
}

/// Adder
/// Adiciona Um servico Agendado a aviao segundo a sua \param matricula
bool BaseDados::updateAviaoServicoCriar(string matricula, servico ser) {
    for(auto av: avioes){
        if(av.getMatricula() == matricula){
            av.addServAgendado(ser);
            return true;
        }
    }
    return false;
}

/// Updater
/// Coloca o Servico Agendado mais recente para os servicos feitos de um aviao pela sua \param matricula
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

/// Updater
/// Atualiza os Parametros de Um Voo
bool BaseDados::updateVoo(int numVoo_s, int numVoo_p, Date data, float duracao, TransporteBagagem t, Aeroporto a1, Aeroporto a2, list<Passageiro> passageiros) {
    list<Voo>::iterator iter;
    for (iter = voos.begin(); iter != voos.end(); iter++) {
        if (iter->getNum() == numVoo_s) {
            list<Passageiro> pass = iter->getPassageiros();
            voos.erase(iter);
            for (Passageiro p : passageiros) {
                pass.push_back(p);
            }
            pass.sort();
            Voo v1(numVoo_p, data, duracao, pass, t, a1, a2);
            voos.push_back(v1);
            voos.sort();
            return true;
        }
    }
    return false;
}

/// Updater
/// Atualiza os Parametros de Um Aeroporto
bool BaseDados::updateAirport(Aeroporto aeroporto, string nome, string cidade, string pais) {
    for(Aeroporto aero: aeroportos){
        list<Aeroporto>::iterator it;
        for(it = aeroportos.begin(); it!= aeroportos.end(); it++){
            if(*it == aeroporto){
                if(nome != "-") (*it).setNome(nome);
                if(cidade != "-") (*it).setCidade(cidade);
                if(pais != "-") (*it).setPais(pais);
                return true;
            }
        }
    }
    return false;
}

/// Updater
/// Atualiza os Parametros de Um Transporte
bool BaseDados::updateTransporte(Aeroporto aeroporto, Transporte transporte, int distancia, string tipo, Time time,
                                 Date date) {
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
    return false;
}

/// Drawer
/// Imprime todos os Serviços do tipo \param tipo
void BaseDados::servicosDraw(string tipo) {
    int spaces = 20;
    cout <<setfill(' ') << setw(spaces) << "ID" << setfill(' ') << setw(spaces) << "Tipo" << setfill(' ') << setw(spaces) << "Funcionario" << setfill(' ') << setw(spaces) << "Data"<< endl;
    cout << string(4 * spaces, '=') << endl;
    for(auto s: servicos){
        if(tipo == s.getTipo()) {
            cout << setfill(' ') << setw(spaces) << s.getID() << setfill(' ') << setw(spaces) << s.getTipo()
                 << setfill(' ') << setw(spaces) << s.getFuncionario() << setfill(' ') << setw(spaces)
                 << s.getData().getDay() << "/" << s.getData().getMonth() << "/" << s.getData().getYear() << endl;
        }
    }
}
