#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l){
  // Pre: l és buida; el canal estandar d’entrada conté un nombre
  // parell d’enters, acabat pel parell 0 0
  // Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
  ParInt p;
  // Se usa el while p.llegir() ya que el llegir es destructivo, retorna un booleano.
  while (p.llegir()){
    l.push_back(p);
  }
}
