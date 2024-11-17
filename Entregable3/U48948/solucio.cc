#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
  /* Pre: 0 <= nota_b <= nota_maxima() */
  /* Post: el resultat és la posició del primer estudiant amb nota major
      o igual que nota_b a vest[0...nest-1]. Si no hi ha estudiants amb 
     nota major o igual que nota_b, el resultat és nest. */
  for (int i = 0; i < nest; ++i) {
    if (vest[i].consultar_nota() >= nota_b) {
      return i;
    }
  }
  return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat)
{
  if (nest >= MAX_NEST) return; // Ensure we do not exceed the maximum number of students
  int dni = est.consultar_DNI();
  int pos = cerca_dicot_per_dni(vest, 0, nest-1, dni);
  trobat = (pos < nest && (vest[pos].consultar_DNI() == dni));
  if (not trobat) {
    // Shift elements to the right to make space for the new student
    for (int i = nest; i > pos; --i) {
      vest[i] = vest[i-1];
    }
    vest[pos] = est; // Insert the new student at the correct position
    nest++; // Increment the number of students
  }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
  int i = posicio_nota(nota_i);
  while (i < nest && vest[i].consultar_nota() <= nota_s) {
    vest[i].escriure();
    ++i;
  }
}