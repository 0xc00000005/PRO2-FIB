#include "BinTree.hh"
#include "sumOfTree.hh"

typedef BinTree<int> BT;

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinTree<int> t){
    int suma;
    if (t.empty()) suma=0;
    else{
        suma = t.value() + sumOfTree(t.left()) + sumOfTree(t.right());
    }
    return suma;
    
}
