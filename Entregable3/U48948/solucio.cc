#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
  /* Pre: 0 <= nota_b <= nota_maxima() */
  /* Post: el resultat és la posició del primer estudiant amb nota major
      o igual que nota_b a vest[0...nest-1]. Si no hi ha estudiants amb 
     nota major o igual que nota_b, el resultat és nest. */
  for (int i = 0; i < nest; ++i) {
    if (vest[i].te_nota() && vest[i].consultar_nota() >= nota_b) {
      return i;
    }
  }
  return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& trobat) {
  int dni = est.consultar_DNI();
  trobat = false;
  int pos = cerca_lineal_per_dni(vest, 0, nest - 1, dni);

  if (pos < nest && vest[pos].consultar_DNI() == dni) {
    trobat = true;
  } else {
    for (int i = nest; i > pos; --i) {
      vest[i] = vest[i - 1];
    }
    vest[pos] = est;
    ++nest;
    if (!est.te_nota()) {
      ++primer_est_amb_nota;
    }
    ordenar();
  }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
  int i = posicio_nota(nota_i);
  while (i < nest) {
    if (vest[i].te_nota() && vest[i].consultar_nota() <= nota_s) { 
      vest[i].escriure();
    }
    ++i;
  }
}
