#include "BinTreeIOParInt.hh"
#include <iostream>


using namespace std;

void busqueda(bool &found, BinTree<ParInt> arbol, int x, int count) {
	if(arbol.value().primer() != 0 and arbol.value().segon() != 0) {
		found = arbol.value().primer()== x;
		if (found) cout << x << " " << arbol.value().segon() << " " << count << endl;
		else {
			busqueda(found, arbol.left(), x, count+1);
			if (!found) busqueda(found, arbol.right(), x, count+1);
		}
	}
}


int main() {
	int n, count = 0;
	bool found;
	BinTree<ParInt> arbol;
	read_bintree_parint(arbol);
	
	while (cin >> n) {
		busqueda(found,arbol,n, count);
		if(!found) cout << -1 << endl;
	}

}