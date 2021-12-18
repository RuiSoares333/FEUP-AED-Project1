#include "BaseDados.h"

int main() {
    BaseDados bd;
    bd.loadAll();
    // menu
    bd.airportDraw();

    bd.saveAll();
    return 0;
}