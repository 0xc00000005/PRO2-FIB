#include <vector>
#include <iostream>
#include "Estudiant.hh"
using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos){
    // Basicamente se usa pos para saber que posicion es reemplazable.
    // Solo adelantas pos cuando has recorrido todas las notas de un estudiante.
    pos = 0;
    for (int i=0; i<v.size(); i++){
        if (v[i].te_nota()){
            if (v[i].consultar_DNI()==v[pos].consultar_DNI()){
                if (v[i].consultar_nota() > v[pos].consultar_nota()){
                    v[pos]=v[i];
                }
            }
            else {
                pos++;
                v[pos]=v[i];

            }
        }
        else{
            if (v[i].consultar_DNI()!=v[pos].consultar_DNI()){
                v[pos]=v[i];
                pos++;
            }
        }
    }
}
