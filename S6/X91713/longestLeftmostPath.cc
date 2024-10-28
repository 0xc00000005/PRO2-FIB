#include "longestLeftmostPath.hh"

// Pre:
// Post: Retorna la llista d'elements que es troben a t, baixant des de l'arrel i
//       seguint el camí més llarg. En cas de varis camins màxims,
//       escull el de més a l'esquerra.
list<int> longestLeftmostPath(BinTree<int> t){
    list<int> l;
    if (t.empty()) return l;
    list<int> l1 = longestLeftmostPath(t.left());
    list<int> l2 = longestLeftmostPath(t.right());
    if (l1.size() > l2.size()) l = l1;
    else l = l2;
    l.push_front(t.value());
    return l;
}