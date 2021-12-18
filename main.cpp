#include "BaseDados.h"

int main() {
    BaseDados bd;
    bd.loadAll();
    bd.saveAll();
    bd.drawVoos();
    return 0;
}