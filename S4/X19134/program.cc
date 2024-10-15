#include "LlistaIOParInt.hh"
#include "ParInt.hh"

using namespace std;

int main(){
   list<ParInt> enteros;
   LlegirLlistaParInt(enteros);
   int n, suma=0;
   int cops=0;
   cin >> n;
   for(list<ParInt>::iterator it = enteros.begin(); it != enteros.end(); ++it){
    ParInt p = *it;
    if(p.primer() == n){
      cops++;
      suma += p.segon();
    }
  }
   cout << n << " " << cops << " " << suma << endl;
}
