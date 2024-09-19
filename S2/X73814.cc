#include <vector>
#include <iostream>
#include "Estudiant.hh"
using namespace std;

vector<Estudiant> recorrer(vector<Estudiant>& v){
    vector<Estudiant> salida;
    for (int i=0; i<v.size(); ++i){
        if(i!=(v.size()-1)){
        if(v[i].consultar_DNI()==v[i+1].consultar_DNI()){
            if (v[i].consultar_nota()>v[i+1].consultar_nota()){
                salida.push_back(v[i]);
            }
            else{
                salida.push_back(v[i+1]);
            }
        }
        }
        else{
            salida.push_back(v[i]);
        }
        i=i+1;
    }
    return salida;
}


int main(){
    vector<Estudiant> entrada;
    int n;
    cin >> n;
    int dni=0;
    double nota=0.0;
    for (int i=0; i<n; ++i){
        cin >> dni;
        cin >> nota;
        entrada[i]=Estudiant(dni);
        entrada[i].afegir_nota(nota);
    }
    vector<Estudiant> exit=recorrer(entrada);
    for (int i=0; i<exit.size(); ++i){
        cout << exit[i].consultar_DNI() << " " << exit[i].consultar_nota() << endl;
    }
    

}