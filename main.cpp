#include "BaseDados.h"
//#include <string>
//#include <iostream>
using namespace std;


void showSubMenu1(){
    cout << "1. Create" << endl;
    cout << "2. Read" << endl;
    cout << "3. Update" << endl;
    cout << "4. Delete" << endl << endl;
    cout << "0. Exit" << endl;
}

void showSubMenuCRUD1(){
    cout << "1. Aeroporto" << endl;
    cout << "2. Aviao" << endl;
    cout << "3. Voo" << endl;
    cout << "4. Transporte" << endl << endl;
    cout << "0. Exit" << endl;
}

void showSubMenuCRUD(){
    cout << "1. Aeroporto" << endl;
    cout << "2. Aviao" << endl;
    cout << "3. Voo" << endl  << endl;
    cout << "0. Exit" << endl;
}

bool respostaExit(){
    char resposta;
    cout << "Deseja Realmente Sair? S-Sim/ N-Nao" << endl;
    cin >> resposta;
    if(resposta == 'S' or resposta == 's' or resposta == '1' or resposta == 'Y' or resposta == 'y'){
        return false;
    } else {
        return true;
    }
}


// -------------------------------------------- CREATE -----------------------------------------------------------------
Transporte createTransporte(BaseDados &based, Aeroporto &aero);

void createAeroporto(BaseDados &based) {
    string nome, cidade, pais;
    cout << "Por favor, insira o nome do aeroporto" << endl;
    cin.ignore();
    getline(cin, nome, '\n');
    cout << "Por favor, insira a cidade onde se encontra o aeroporto" << endl;
    getline(cin, cidade, '\n');
    cout << "Por favor, insira o pais onde se encontra o aeroporto" << endl;
    getline(cin, pais, '\n');
    Aeroporto aero(nome, pais, cidade);

    int count;
    cout << "Quantos transportes deseja inserir no aeroporto?" << endl;
    while(true){
        cin >> count;
        if(count < 1){
            cout << "Necessario pelo menos 1 transporte. Por favor insira o numero de transportes outra vez:" << endl;
        }
        else break;
    }
    for(int i = 0; i < count; i++){
        Transporte transporte = createTransporte(based, aero);
        aero.insertTransporte(transporte);
    }

    based.addAirport(aero);
    based.airportSort();
}

Transporte createTransporte(BaseDados &based, Aeroporto &aero){
    string tipo;
    int distancia, hora, minuto, day, month, year;
    cout << "Que tipo de transporte deseja adicionar? ('metro', 'autocarro', 'comboio')" << endl;
    cin >> tipo;
    cout << "Insira a data do transporte. (dd mm yyyy)" << endl;
    cin >> day >> month >> year;
    cout << "Insira o tempo do transporte. (hh mm)" << endl;
    cin >> hora  >> minuto;
    cout << "Finalmente insira a distancia do transporte ao aeroporto em metros." << endl;
    cin >> distancia;

    Date date(day, month, year);
    Time time(hora, minuto);
    Transporte transporte(distancia, time, tipo, date);

    return transporte;
}

servico createServico(){
    int id, y, m, d; string tipo, funcionario;
    cout << "Por favor, insira o ID do Servico." << endl;
    cin >> id;
    cout << "Por favor, insira o Tipo do Servico. (Manutencao/Limpeza)" << endl;
    cin >> tipo;
    cout << "Por favor, insira o Funcionario encarregue." << endl;
    cin >> funcionario;
    cout << "Por favor, insira o ano do Servico." << endl;
    cin >> y;
    cout << "Por favor, insira o mes do Servico." << endl;
    cin >> m;
    cout << "Por favor, insira o dia do Servico." << endl;
    cin >> d;
    Date data(d, m, y);
    servico s(id, tipo, funcionario, data);
    return s;
}

Voo createVoo(BaseDados &bd) {
    int numVoo, day, month, year, c, n, m;
    float duracaoVoo;
    list<Passageiro> passageiros;
    char input;
    cout << "Insira o numero do voo: ";
    cin >> numVoo;
    cout << endl;
    cout << "Insira a data no formato dia mes ano: ";
    cin >> day >> month >> year;
    Date dataPartida(day, month, year);
    cout << endl;
    cout << "Insira a duracao do voo em horas: ";
    cin >> duracaoVoo;
    cout << endl;
    cout << "Insira o numero de carruagens do transporte: ";
    cin >> c;
    cout << endl;
    cout << "Insira o numero de pilhas por carruagem: ";
    cin >> n;
    cout << endl;
    cout << "Insira o numero de malas por pilha: ";
    cin >> m;
    cout << endl;
    TransporteBagagem transporteBagagem(c, n, m);
    do {
        cout << "Pretende adicionar passageiros ao voo? S-Sim/ N-Nao" << endl;
        cin >> input;
        if (input == 'S') {
            string nome;
            int id, numBil;
            char in;
            bool checkin;
            bool checkbag;
            vector<Bilhete> bilhetes;
            vector<Bagagem> bagagem;
            float comprimento, largura, altura, peso;
            cout << "Insira o nome do passageiro: ";
            cin >> nome;
            cout << endl;
            cout << "Insira o id do passageiro: ";
            cin >> id;
            cout << endl;
            cout << "Insira o numero do bilhete: ";
            cin >> numBil;
            cout << endl;
            cout << "O check-in e automatico? S-Sim/ N-Nao" << endl;
            cin >> in;
            if (in == 'S') checkin = true;
            else checkin = false;
            cout << "Possui bagagem? S-Sim/ N-Nao" << endl;
            cin >> in;
            if (in == 'S') {
                checkbag = true;
                cout << "Insira o comprimento, largura, altura (cm) e peso (kg) da bagagem: ";
                cin >> comprimento >> largura >> altura >> peso;
                bagagem.push_back(Bagagem(comprimento, largura, altura, peso));
            } else checkbag = false;

            bilhetes.push_back(Bilhete(numBil, checkbag, checkin));
            char inp;
            cout << "Pretende adicionar mais bilhetes a este passageiro? S-Sim/ N-Nao" << endl;
            cin >> inp;
            while (inp != 'N') {
                cout << "Insira o numero do bilhete: ";
                cin >> numBil;
                cout << endl;
                cout << "O check-in e automatico? S-Sim/ N-Nao" << endl;
                cin >> in;
                if (in == 'S') checkin = true;
                else checkin = false;
                cout << "Possui bagagem? S-Sim/ N-Nao" << endl;
                cin >> in;
                if (in == 'S') {
                    checkbag = true;
                    cout << "Insira o comprimento, largura, altura (cm) e peso (kg) da bagagem: ";
                    cin >> comprimento >> largura >> altura >> peso;
                    bagagem.push_back(Bagagem(comprimento, largura, altura, peso));
                } else checkbag = false;
            }
            passageiros.push_back(Passageiro(nome, id, bilhetes, bagagem));
        }
    } while (input != 'N');
        Voo v1(numVoo, dataPartida, duracaoVoo, passageiros, transporteBagagem);
        bd.addVoo(v1);
        return v1;
}

void createAviao(BaseDados &bd){
    string matricula; int capacidade; char input;
    cout << "Por favor, insira a Matricula do Aviao." << endl;
    cin >> matricula;
    cout << "Por favor, insira a Capacidade do Aviao." << endl;
    cin >> capacidade;
    Aviao a(matricula, capacidade);

    do{
        cout << "Pretende agendar servicos? S-Sim/ N-Nao" << endl;
        cin >> input;
        if(input == 'S'){
            servico s = createServico();
            a.addServAgendado(s);
            bd.addServico(s);
        }
    } while (input != 'N');

    do{
        cout << "Pretende agendar Voos? S-Sim/ N-Nao" << endl;
        cin >> input;
        if(input == 'S'){
            Voo v = createVoo(bd);
            a.adicionarVoo(v);
        }
    } while (input != 'N');
    bd.addAviao(a);
    cout << "Aviao Adicionado Com Sucesso!" << endl;
}


void subMenuCreate(BaseDados &bd){
    char input;
    do{
        showSubMenuCRUD();
        cin >> input;
        switch (input) {
            case '1':
                createAeroporto(bd);
                break;
            case '2':
                createAviao(bd);
                break;
            case '3':
                createVoo(bd);
                break;
        }
    } while(input != '0');
}



// ---------------------------------------------- READ -----------------------------------------------------------------

void avioesShow(BaseDados &bd){
    cout << "Como Pretende Visualizar os Avioes?\n1. Matricula\n2. Capacidade\n3. Numero de Voos Planeados\n4. Numero de Servicos Agendados\n5. Numero de Servicos Planeados" << endl;
    char input;
    cin >> input;
    switch(input){
        case '2':
            bd.drawAvioesCap();
            break;
        case '3':
            bd.drawAvioesVoo();
            break;
        case '4':
            bd.drawAvioesSerAg();
            break;
        case '5':
            bd.drawAvioesSerTer();
            break;
        default:
            bd.drawAvioes(bd.getAvioes());
            break;
    }
}

void voosShow(BaseDados &bd) {
    cout << "Pretende ordenar os voos por qual atributo?\n1. Numero do voo\n2. Data de Partida\n3. Duracao do voo\n4. Numero de passageiros" << endl;
    char input;
    switch(input) {
        case '1':
            bd.drawVoos(bd.getVoos());
            break;
        case '2':
            bd.drawVoosData();
    }
}

void subMenuRead(BaseDados &bd){
    char input;
    do{
        showSubMenuCRUD1();
        cin >> input;
        switch (input) {
            case '1':
                bd.airportDraw();
                break;
            case '2':
                avioesShow(bd);
                break;
            case '3':
                voosShow(bd);
                break;
            case '4': {
                string nome, cidade, pais;
                cout << "Qual o nome do aeroporto de onde quer ver os transportes?" << endl;
                cin.ignore();
                getline(cin, nome, '\n');
                cout << "Por favor, insira a cidade onde se encontra o aeroporto" << endl;
                getline(cin, cidade, '\n');
                cout << "Por favor, insira o pais onde se encontra o aeroporto" << endl;
                getline(cin, pais, '\n');
                Aeroporto aero(nome, pais, cidade);

                bd.transportDraw(aero);
            }
        }
    } while(input != '0');
}


// -------------------------------------------- UPDATE -----------------------------------------------------------------
void updateAeroporto(BaseDados &bd, Aeroporto aeroporto){
    string nome, cidade, pais;
    cout << "Vai ser pedido para inserir o novo nome, cidade e pais do aeroporto. Se nao desejar alterar um destes deve inserir '-'" << endl;
    cout << "Qual o novo nome do aeroporto?" << endl;
    cin >> nome;
    cout << "Qual a nova cidade do aeroporto?" << endl;
    cin >> cidade;
    cout << "Qual o novo pais do aeroporto?" << endl;
    cin >> pais;

    bool check = bd.updateAirport(aeroporto, nome, cidade, pais);
    if(check) cout << "Aeroporto atualizado com successo!" << endl;
    else cout << "Erro! Nao foi possivel atualizar o aeroporto" << endl;
    bd.airportSort();
}

void updateAviao(BaseDados &bd, string matricula){

    char input;
    do{
        cout << "Adicionar Voo? S-Sim/ N-Nao" << endl;
        cin >> input;
        if(input == 'S'){
            Voo v = createVoo(bd);
            if(bd.updateAviaoVoo(matricula, v)){
                cout << "Voo Adicionado!" << endl;
            } else{
                cout << "Erro! Nao foi possivel atualizar o parametro!" << endl;
            }
        }
    } while (input != 'N');

    do{
        cout << "Adicionar Servico? S-Sim/ N-Nao" << endl;
        cin >> input;
        if(input == 'S'){
            servico s = createServico();
            if(bd.updateAviaoServicoCriar(matricula, s)){
                cout << "Servico Adicionado!" << endl;
            } else {
                cout << "Erro! Nao foi possivel atualizar o parametro!" << endl;
            }
        }
    } while (input != 'N');

    do{
        cout << "Completar Servico? S-Sim/ N-Nao" << endl;
        cin >> input;
        if(input == 'S'){
            if(bd.updateAviaoServicoTerminar(matricula)){
                cout << "Servico Terminado!" << endl;
            } else {
                cout << "Erro! Nao foi possivel atualizar o parametro!" << endl;
            }
        }
    } while (input != 'N');

}

void updateTransporte(BaseDados &bd, Aeroporto aeroporto, Transporte transporte) {
    int distancia, hora, minuto, dia, mes, ano;
    string tipo;
    char sep;
    cout << "Vai ser pedido para inserir a nova distancia, o novo tipo, a nova data e o novo tempo do transporte."
         << endl;
    cout << "Insira o novo tipo do transporte. Se nao o pretender alterar insira '-'." << endl;
    cin >> tipo;
    cout << "Insira a nova distancia do transporte ao aeroporto. Se nao o pretender alterar insira '0'." << endl;
    cin >> distancia;
    cout << "Insira a nova data do transporte no formato dd/mm/yyyy. Se nao pretender alterar insira '00/00/0000'" << endl;
    cin >> dia >> sep >> mes >> ano;
    cout << "Insira a nova hora do transporte no formato hh:mm. Se nao pretender alterar insira 24:00" << endl;
    cin >> hora >> sep >> minuto;

    Time time(hora, minuto);
    if (hora == 24) time = transporte.getTime();
    Date date(dia, mes, ano);
    if(dia == 0 || mes == 0 || ano == 0) date = transporte.getDate();
    if(tipo == "-") tipo = transporte.getTipo();
    if(distancia == 0) distancia = transporte.getDistancia();

    bool check = bd.updateTransporte(aeroporto, transporte, distancia, tipo, time, date);
    if(check) cout << "Transporte alterado com successo!" << endl;
    else cout << "Erro! Transporte nao alterado." << endl;
}

void updateVoo(BaseDados &bd) {
    int numVoo_s, numVoo_p, dia, mes, ano, c, n, m;
    float duracao;
    cout << "Insira o numero do voo que pretende alterar: ";
    cin >> numVoo_s;
    cout << endl;
    cout << "Qual o novo numero? ";
    cin >> numVoo_p;
    cout << endl;
    cout << "Qual o novo dia, mes e ano? ";
    cin >> dia >> mes >> ano;
    cout << endl;
    Date d(dia, mes, ano);
    cout << "Qual a nova duracao do voo? ";
    cin >> duracao;
    cout << endl;
    cout << "Insira o novo numero de carruagens do transporte: ";
    cin >> c;
    cout << endl;
    cout << "Insira o novo numero de pilhas por carruagem: ";
    cin >> n;
    cout << endl;
    cout << "Insira o novo numero de malas por pilha: ";
    cin >> m;
    cout << endl;
    TransporteBagagem t(c, n, m);
    bd.updateVoo(numVoo_s, numVoo_p, d, duracao, t);
}

void updatePassageiros(BaseDados &bd) {
    char input;
    list<Passageiro> passageiros;
    do {
        cout << "Pretende substituir os passageiros do voo? S-Sim/ N-Nao" << endl;
        cin >> input;
        if (input == 'S') {
            string nome;
            int id, numBil;
            char in;
            bool checkin;
            bool checkbag;
            vector<Bilhete> bilhetes;
            vector<Bagagem> bagagem;
            float comprimento, largura, altura, peso;
            cout << "Insira o nome do passageiro: ";
            cin >> nome;
            cout << endl;
            cout << "Insira o id do passageiro: ";
            cin >> id;
            cout << endl;
            cout << "Insira o numero do bilhete: ";
            cin >> numBil;
            cout << endl;
            cout << "O check-in e automatico? S-Sim/ N-Nao" << endl;
            cin >> in;
            if (in == 'S') checkin = true;
            else checkin = false;
            cout << "Possui bagagem? S-Sim/ N-Nao" << endl;
            cin >> in;
            if (in == 'S') {
                checkbag = true;
                cout << "Insira o comprimento, largura, altura (cm) e peso (kg) da bagagem: ";
                cin >> comprimento >> largura >> altura >> peso;
                bagagem.push_back(Bagagem(comprimento, largura, altura, peso));
            } else checkbag = false;

            bilhetes.push_back(Bilhete(numBil, checkbag, checkin));
            char inp;
            cout << "Pretende adicionar mais bilhetes a este passageiro? S-Sim/ N-Nao" << endl;
            cin >> inp;
            while (inp != 'N') {
                cout << "Insira o numero do bilhete: ";
                cin >> numBil;
                cout << endl;
                cout << "O check-in e automatico? S-Sim/ N-Nao" << endl;
                cin >> in;
                if (in == 'S') checkin = true;
                else checkin = false;
                cout << "Possui bagagem? S-Sim/ N-Nao" << endl;
                cin >> in;
                if (in == 'S') {
                    checkbag = true;
                    cout << "Insira o comprimento, largura, altura (cm) e peso (kg) da bagagem: ";
                    cin >> comprimento >> largura >> altura >> peso;
                    bagagem.push_back(Bagagem(comprimento, largura, altura, peso));
                } else checkbag = false;
            }
            passageiros.push_back(Passageiro(nome, id, bilhetes, bagagem));
        }
    } while (input != 'N');
}

void subMenuUpdate(BaseDados &bd){
    char input;
    do{
        showSubMenuCRUD();
        string matricula;
        cin >> input;
        switch (input) {
            case '1':{
                string nome, cidade, pais;
                cout << "Por favor, insira o nome do aeroporto" << endl;
                cin.ignore();
                getline(cin, nome, '\n');
                cout << "Por favor, insira a cidade onde se encontra o aeroporto" << endl;
                getline(cin, cidade, '\n');
                cout << "Por favor, insira o pais onde se encontra o aeroporto" << endl;
                getline(cin, pais, '\n');
                Aeroporto aero(nome, pais, cidade);
                updateAeroporto(bd, aero);
                break;
            }
            case '2':
                cout << "Insira a Matricula do Aviao que quer alterar." << endl;
                cin >> matricula;
                updateAviao(bd, matricula);
                break;
            case '3':
                updateVoo(bd);
                break;
        }
    } while(input != '0');
}


// -------------------------------------------- DELETE -----------------------------------------------------------------
void removeTransporte(BaseDados &based, Aeroporto aero){
    string tipo;
    int distancia, hora, minuto, day, month, year;
    cout << "Insira as caracteristicas do transporte que quer remover \n Se existir sera removido." << endl;
    cout << "Que tipo de transporte deseja remover? ('metro', 'autocarro', 'comboio')" << endl;
    cin >> tipo;
    cout << "Insira a data do transporte. (dd mm yyyy)" << endl;
    cin >> day >> month >> year;
    cout << "Insira o tempo do transporte. (hh mm)" << endl;
    cin >> hora >> minuto;
    cout << "Finalmente insira a distancia do transporte ao aeroporto em metros." << endl;
    cin >> distancia;

    Date date(day, month, year);
    Time time(hora, minuto);
    Transporte transporte(distancia, time, tipo, date);
    bool check = based.removeTransporte(aero, transporte);
    if(check) cout << "Transporte removido do aeroporto com successo!" << endl;
    else cout << "Erro! E possivel que o transporte ou o aeroporto nao existam." << endl;
}

void removeAirport(BaseDados &bd){
    string nome, pais, cidade;
    cout << "Insira as caracteristicas do aeroporto que quer remover \n Se existir sera removido" << endl;
    cout << "Qual o nome do aeroporto?" << endl;
    cin >> nome;
    cout << "Qual a cidade onde o aeroporto se encontra?" << endl;
    cin >> cidade;
    cout << "Qual o pais onde o aeroporto se encontra?" << endl;
    cin >> pais;

    Aeroporto aeroporto(nome, pais, cidade);
    bool check = bd.removeAirport(aeroporto);
    if(check) cout << "Aeroporto removido com successo!" << endl;
    else cout << "Erro! E possivel que o aeroporto nao exista" << endl;
    bd.airportSort();
}

void removeAviao(BaseDados &bd){
    string matricula;
    cout << "Insira a Matricula do Aviao que quer Remover." << endl;
    cin >> matricula;
    bd.removeAviao(matricula);
}

void removeVoo(BaseDados &bd) {
    int numVoo;
    cout << "Insira o numero do voo que pretende remover" << endl;
    cin >> numVoo;
    bd.removeVoo(numVoo);
}

void subMenuDelete(BaseDados &bd){
    char input;
    do{
        showSubMenuCRUD1();
        cin >> input;
        string matricula;
        switch (input) {
            case '1':
                removeAirport(bd);
                break;
            case '2':
                removeAviao(bd);
                break;
            case '3':
                removeVoo(bd);
                break;
            case '4':
                string nome, cidade, pais;
                cout << "Qual o nome do aeroporto de onde quer remover o transportes" << endl;
                cin.ignore();
                getline(cin, nome, '\n');
                cout << "Por favor, insira a cidade onde se encontra o aeroporto" << endl;
                getline(cin, cidade, '\n');
                cout << "Por favor, insira o pais onde se encontra o aeroporto" << endl;
                getline(cin, pais, '\n');
                Aeroporto aero(nome, pais, cidade);

                removeTransporte(bd, aero);
                break;
        }
    } while(input != '0');
}


int main() {
    BaseDados bd;
    bd.loadAll();

    char input;
    bool respostaSair = true;
    do{
        showSubMenu1();
        cin >> input;

        switch(input){
            case '1':
                subMenuCreate(bd);
                break;
            case '2':
                subMenuRead(bd);
                break;
            case '3':
                subMenuUpdate(bd);
                break;
            case '4':
                subMenuDelete(bd);
                break;
            default:
                cout << endl;
        }

        if(input == '0'){respostaSair = respostaExit();}

    }while(input!='0' and respostaSair);

    bd.saveAll();
    return 0;
}
