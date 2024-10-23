#include "BinTreeIOParInt.hh"
#include <iostream>

using namespace std;

void read_bintree_parint(BinTree<ParInt>& a){
	ParInt entrada;
	entrada.llegir();
	BinTree<ParInt> bl,br;	
	if (entrada.primer()!= 0 && entrada.segon()!=0){
		read_bintree_parint(bl);
		read_bintree_parint(br);
	}
	BinTree<ParInt> b(entrada,bl,br);
	a=b;
}