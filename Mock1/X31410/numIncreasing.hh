#include <iostream>

using namespace std;

#include "BinTree.hh"

void frecursiva(BinTree<int> t, int &comptador, int valoranterior);
// Pre:
// Post: Retorna el nombre de nodes de t que no son l'arrel de t i que guarden un valor
//       estríctament major que el valor guardat al seu node pare.
int numIncreasing(BinTree<int> t);

