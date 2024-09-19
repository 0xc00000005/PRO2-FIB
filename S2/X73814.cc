#include <vector>
#include <iostream>
#include "Estudiant.hh"
using namespace std;

vector<Estudiant> recorrer(vector<Estudiant>& v, int n){
    vector<Estudiant> salida(n);
    // Ara tenim totes les entrades, pero falta filtrar per nota, i sino DNI.
    // Primer creem un estudiant bogus per a comparar
    int dni = v[0].consultar_DNI();
    Estudiant bogus(dni);
    salida[0]=bogus;
    int j=0;
    // Creamos la variable j para poder modificar el elemento anterior en caso que sea necesario.
    if(v[0].te_nota()) salida[0].afegir_nota(v[0].consultar_nota());
	for (int i = 1; i < v.size(); ++i) {
		if (v[i].consultar_DNI() != dni) {
			++j;
			dni = v[i].consultar_DNI();
			Estudiant x(dni);
			salida[j] = x;
			if(v[i].te_nota()) salida[j].afegir_nota(v[i].consultar_nota());
		}
		else if (v[i].te_nota()){
			if (salida[j].te_nota()) {
				if (salida[j].consultar_nota() < v[i].consultar_nota()) salida[j].modificar_nota(v[i].consultar_nota());
			}
			else salida[j].afegir_nota(v[i].consultar_nota());
		}
	}
    return salida;
}


int main(){
    int n;
    cin >> n;
    int dni=-1;
    int n_deb=0;
    vector<Estudiant> entrada(n);
    for (int i=0; i<n; ++i){
        entrada[i].llegir();
        if(entrada[i].consultar_DNI()!=dni){
            n_deb=n_deb+1;
        }
        dni=entrada[i].consultar_DNI();
    }
    // n_deb se suposa que es el nombre d'estudiants diferents
    vector<Estudiant> sortida(n_deb);
    sortida=recorrer(entrada, n_deb);
        for(int j=0; j<sortida.size(); ++j){
            sortida[j].escriure();
        }

}