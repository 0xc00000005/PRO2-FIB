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
  int pos;

  if (est.te_nota()) {
    // Search in the range of students with grades
    pos = cerca_dicot_per_dni(vest, primer_est_amb_nota, nest - 1, dni);
    if (pos < nest && vest[pos].consultar_DNI() == dni) {
      trobat = true;
    } else {
      // Shift elements to the right to make space for the new student
      for (int i = nest; i > pos; --i) {
        vest[i] = vest[i - 1];
      }
      vest[pos] = est;
      ++nest;
    }
  } else {
    // Search in the range of students without grades
    pos = cerca_dicot_per_dni(vest, 0, primer_est_amb_nota - 1, dni);
    if (pos < primer_est_amb_nota && vest[pos].consultar_DNI() == dni) {
      trobat = true;
    } else {
      // Shift elements to the right including students with grades
      for (int i = nest; i > pos; --i) {
        vest[i] = vest[i - 1];
      }
      vest[pos] = est;
      ++nest;
      ++primer_est_amb_nota; // Update the index of first student with grade
    }
  }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
  int i = posicio_nota(nota_i);
  while (i < nest) {
    if (vest[i].te_nota() && vest[i].consultar_nota() <= nota_s) { // Check if the student has a grade and if the grade is within the range
      vest[i].escriure();
    }
    ++i;
  }
}