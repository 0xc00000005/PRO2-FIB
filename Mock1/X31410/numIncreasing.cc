#include "numIncreasing.hh"

typedef BinTree<int> BT;
// Nombre de nodes valor > que el node pare


void frecursiva(BT t, int &comptador, int valoranterior) {
    if (!t.empty()) {
        if (t.value() > valoranterior) ++comptador;
        BT tleft = t.left();
        BT tright = t.right();
        frecursiva(tleft, comptador, t.value());
        frecursiva(tright, comptador, t.value());
        //cout << comptador << endl;
    }
}

int numIncreasing(BT t){
    int comptador=0;
    int valoranterior=t.value();
    frecursiva(t, comptador, valoranterior);
    return comptador;
}
