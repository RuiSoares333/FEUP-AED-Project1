
#include "Aeroporto.h"


/// Construtor
/// \param nome
/// \param pais
/// \param cidade
/// \inicializa uma BST de objetos Transporte vazia
Aeroporto::Aeroporto(string nome, string pais, string cidade):transportes(Transporte()){
    this->nome = nome;
    this->pais = pais;
    this->cidade = cidade;
}

/// Getter
/// \return \param nome do aeroporto
string Aeroporto::getNome() const {
    return nome;
}

/// Getter
/// \return \param país onde o aeroporto se encontra
string Aeroporto::getPais() const {
    return pais;
}

/// Getter
/// \return \param cidade onde o aeroporto se encontra
string Aeroporto::getCidade() const {
    return cidade;
}

/// Setter
/// \param nome
/// \muda o nome do aeroporto
void Aeroporto::setNome(string nome) {
    this->nome = nome;
}

/// Setter
/// \param pais
/// \muda o país onde o aeroporto se encontra
void Aeroporto::setPais(string pais) {
    this->pais = pais;
}

/// Setter
/// \param cidade
/// \muda a cidade onde o aeroporto se encontra
void Aeroporto::setCidade(string cidade) {
    this->cidade = cidade;
}

/// Getter
/// \return \param transportes (uma cópia da BST de objetos Transporte do aeroporto)
const BST<Transporte> &Aeroporto::getTransportes() const {
    return transportes;
}

/// Setter
/// \param BST de objetos Transporte
/// \muda a arvore que contem os transportes do aeroporto
void Aeroporto::setTransportes(const BST<Transporte> &transportes) {
    this->transportes = transportes;
}

/// \parâmetro Objeto da classe Transporte
/// \adiciona um transporte ao aeroporto
/// \adiciona uma objeto da classe Transporte à BST do aeroporto
bool Aeroporto::insertTransporte(Transporte &transporte) {
    return transportes.insert(transporte);
}

/// parâmetro Objeto da classe Transporte
/// \remove o transporte do aeroporto
/// \remove da BST do aeroporto o Objeto da classe Transporte que vem como parâmetro
bool Aeroporto::removeTransporte(Transporte &transporte) {
    return transportes.remove(transporte);
}

/// adiciona o nome, a cidade e o país ao "aeroporto_all_save".txt
/// \guarda no ficheiro "aeroporto_{nome}_{cidade}_{país}_save.txt" as informações
/// \do aeroporto e dos transportes guardados na sua BST
/// \return false se não conseguir abrir o ficheiro, ou se não o conseguir criar
bool Aeroporto::saveFile() {
    int distancia, day, year, month, hora, minuto;
    string tipo;
    ofstream save_all;

    save_all.open("aeroporto_all_save.txt", ios_base::app);
    save_all << nome << " " << cidade << " " << pais << endl;
    save_all.close();

    ofstream save_stream;
    save_stream.open("aeroporto_"+nome + "_" + cidade + "_" + pais + "_save.txt");
    if(save_stream.is_open()){
        save_stream << nome << " " << cidade << " " << pais << endl;

        BSTItrIn<Transporte> it(transportes);
        while(!it.isAtEnd()){
            distancia = it.retrieve().getDistancia();
            tipo = it.retrieve().getTipo();
            day = it.retrieve().getDate().getDay();
            month = it.retrieve().getDate().getMonth();
            year = it.retrieve().getDate().getYear();
            hora = it.retrieve().getTime().getHora();
            minuto = it.retrieve().getTime().getMinuto();

            save_stream << distancia << " " << tipo << " " << day << " " << month << " " << year << " " << hora << " " << minuto << endl;
            it.advance();
        }
        save_stream.close();
        return true;
    }
    else return false;
}

/// procura o ficherio "aeroporto_{nome}_{cidade}_{país}_save.txt" que corresponde ao objeto
/// \atualiza os parametros do objeto para aqueles guardados no ficheiro
/// \cria objetos da classe Transporte com os parâmetros em cada linha e adiciona-os" à BST do aeroporto
bool Aeroporto::loadFile() {
    int distancia, day, year, month, hora, minuto;
    string tipo, nome, cidade, pais;
    ifstream load_stream;
    load_stream.open("aeroporto_"+ this->nome + "_" + this->cidade + "_" + this->pais + "_save.txt");
    if(load_stream.is_open()){
        load_stream >> nome >> cidade >> pais;

        while(!(load_stream.eof())){
            load_stream >> distancia >> tipo >> day >> month >> year >> hora >> minuto;
            Time time(hora, minuto);
            Date date(day, month, year);
            Transporte transporte(distancia, time, tipo, date);
            transportes.insert(transporte);
        }

        load_stream.close();
        return true;
    }
    else return false;
}

/// Operator
/// Operador "<" de acordo com pais, cidade e nome, alfabeticamente
bool const Aeroporto::operator<(const Aeroporto &a2) const {
    if(pais == a2.getPais()){
        if(cidade == a2.getCidade()) return nome < a2.getNome();
        return cidade < a2.getCidade();
    }
    return pais < a2.getPais();
}

/// Operator
/// Operador "==" de acordo com pais, cidade e nome
bool const Aeroporto::operator==(const Aeroporto &a2) const{
    if(nome == a2.getNome()){
        if(cidade == a2.getCidade()){
            return pais == a2.getPais();
        }
        return false;
    }
    return false;
}

/// Constructor
/// Construtor Vazio Com Valores Default
Aeroporto::Aeroporto() :transportes(Transporte()){
    nome = "zzzzzzzzzzzzzzzzzzz";
    cidade = "zzzzzzzzzzzzzzzzzzzz";
    pais = "zzzzzzzzzzzzzzzzzzzzzz";
}
