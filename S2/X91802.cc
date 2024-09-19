#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v){
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
   resultat es la posicio de l'estudiant de nota maxima de v i la segona
   component es la posicio de l'estudiant de nota minima de v (si hi ha
   empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
   hi ha cap estudiant amb nota, totes dues components valen -1 */
    double nota_max=-1;
    double nota_min=11;
    int pos_max=0;
    int pos_min=0;
    int dni_max=0;
    int dni_min=0;
    bool negatiu=true;
   for (int i = 0; i < v.size(); i++) {
        if (v[i].te_nota()) {
            negatiu = false;
            double nota = v[i].consultar_nota();
            int dni = v[i].consultar_DNI();

            if (nota > nota_max) {
                nota_max = nota;
                pos_max = i;
                dni_max = dni;
            } else if (nota == nota_max) {
                if (dni < dni_max) {
                    pos_max = i;
                    dni_max = dni;
                }
            }

            if (nota < nota_min) {
                nota_min = nota;
                pos_min = i;
                dni_min = dni;
            } else if (nota == nota_min) {
                if (dni < dni_min) {
                    pos_min = i;
                    dni_min = dni;
                }
            }
        }
    }

   if (negatiu) return make_pair(-1, -1);
   else return make_pair(pos_max, pos_min);
}

