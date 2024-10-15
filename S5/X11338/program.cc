#include "BinTree.hh"
#include "ParInt.hh"

/*Pre: a = A */
/*Post: a es com a A amb k sumat al segon component de cada node */
void sumak(BinTree<ParInt>& a, int k){
    if (!a.empty()){
        BinTree<ParInt> l=a.left();
        BinTree<ParInt> r=a.right();
        sumak(l,k);
        sumak(r,k);
        ParInt valor(a.value().primer(), ((a.value().segon())+k));
        a=BinTree<ParInt>(valor, l, r);
    }
}
