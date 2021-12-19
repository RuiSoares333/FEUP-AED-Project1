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

void showSubMenuCRUD(){
    cout << "1. Aeroporto" << endl;
    cout << "2. Aviao" << endl;
    cout << "3. Voo" << endl  << endl;
    cout << "0. Exit" << endl;
}

bool respostaExit(){
    char resposta;
    cout << "Deseja Realmente sair? S-Sim/ N-Nao" << endl;
    cin >> resposta;
    if(resposta == 'S' or resposta == 's' or resposta == '1' or resposta == 'Y' or resposta == 'y'){
        return false;
    } else {
        return true;
    }
}

bool handleCRUDInput(){

}

void subMenuCreate(){
    char input;
    do{
        showSubMenuCRUD();
        cin >> input;
    } while(input != '0');
}

void subMenuRead(){
    char input;
    do{
        showSubMenuCRUD();
        cin >> input;
    } while(input != '0');
}

void subMenuUpdate(){
    char input;
    do{
        showSubMenuCRUD();
        cin >> input;
    } while(input != '0');
}

void subMenuDelete(){
    char input;
    do{
        showSubMenuCRUD();
        cin >> input;
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
                subMenuCreate();
                break;
            case '2':
                subMenuRead();
                break;
            case '3':
                subMenuUpdate();
                break;
            case '4':
                subMenuDelete();
                break;
            default:
                cout << endl;
        }

        if(input == '0'){respostaSair = respostaExit();}

    }while(input!='0' and respostaSair);

    bd.saveAll();
    return 0;
}
