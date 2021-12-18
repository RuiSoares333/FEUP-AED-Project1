#include "BaseDados.h"

int main() {
    BaseDados bd;
    bd.loadAll();
    bd.transportDraw(bd.getAeroportos().front());
    bd.saveAll();
    return 0;
}