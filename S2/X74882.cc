#include <vector>
#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
using namespace std;

void modify (Cjt_estudiants& cjt, Cjt_estudiants& cjt2) {
	for(int i=0; i<cjt.mida(); i++) {
		Estudiant a = cjt.consultar_iessim(i+1);
		Estudiant b = cjt2.consultar_iessim(i+1);

		if (a.te_nota() && b.te_nota() && (a.consultar_nota() < b.consultar_nota())) {
			cjt.modificar_iessim(i+1,b);
		}
		else if (!a.te_nota() && b.te_nota()) {
			cjt.modificar_iessim(i+1,b);
		}
	}
}

int main() {
	//Declaraciones
	Cjt_estudiants cjt, cjt2;

	//Leer conjuntos de estudiantes
	cjt.llegir();
	cjt2.llegir();

	//Actualizar el primer conjunto
	modify(cjt,cjt2);

	//Escribir el conjunto cjt actualizado
	cjt.escriure();
}