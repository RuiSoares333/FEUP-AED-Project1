#include <iostream>
#include "Transporte.h"
#include "Aeroporto.h"
using namespace std;


int main() {
    BST<Transporte> transportes{Transporte()};
    Aeroporto aeroporto("nome", "pais", "cidade");
    aeroporto.setTransportes(transportes);
    cout<<"check 1" << endl;
    Date d1(15, 12, 2021);
    Time t1(15, 30);
    Date d2(14, 12, 2021);
    Time t2(18, 30);
    Date d3(15, 12, 2021);
    Time t3(11, 30);
    cout<<"check 2" << endl;
    Transporte tr1(10, t1, "Autocarro", d1);
    Transporte tr2(15, t2, "comboio", d2);
    Transporte tr3(9, t3, "metro", d3);
    cout<<"check 3" << endl;
    aeroporto.insertTransporte(tr1);
    aeroporto.insertTransporte(tr2);
    aeroporto.insertTransporte(tr3);
    cout<<"check 4" << endl;

    bool res, res2;
    res = aeroporto.saveFile();
    cout << res;

    Date d4(15, 12, 2022);
    Time t4(20, 30);
    Transporte tr4(30, t4, "metro", d4);
    aeroporto.insertTransporte(tr4);
    cout << "check 5" << endl;

    res2 = aeroporto.loadFile();
    cout << res2;

    BST<Transporte> transportes2 = aeroporto.getTransportes();
    BSTItrIn<Transporte> it(transportes2);
    Transporte test1 = it.retrieve();
    cout << '\n' << test1.getTime().getHora() << test1.getTime().getMinuto() << endl;
    it.advance();
    Transporte test2 = it.retrieve();
    cout << '\n' << test2.getTime().getHora() << test2.getTime().getMinuto() << endl;

    return 0;
}
