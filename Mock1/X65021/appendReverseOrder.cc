#include "appendReverseOrder.hh"

// Pre: Sigui [x0,x1,x2,...,x{n-1}] el valor inicial de l.
// Post: El valor de l és [x0,x1,x2,...,x{n-1},x{n-1},...,x2,x1,x0].
//       A més a més, els elements inicials de la llista han persistit i
//       no han canviat de valor, i ocupen les posicions del principi.
void appendReverseOrder(list<int> &l){
    list<int> copia;
    for (auto const& element : l){
        copia.push_front(element);
    }
    for (auto const& element : copia){
        l.push_back(element);
    }
}