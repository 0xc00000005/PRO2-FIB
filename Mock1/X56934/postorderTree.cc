#include "postorderTree.hh"

void postorderTree(const BinTree<int>& t, BinTree<int>& newTree, int& counter) {
    // t original, newTree nuevo, counter postorden
    if (!t.empty()) {
        BinTree<int> left, right;
        postorderTree(t.left(), left, counter); // LEFT
        postorderTree(t.right(), right, counter); // RIGHT
        // Ya que el postorden es left, right, nodo
        newTree = BinTree<int>(counter++, left, right); // NODO
    }
}
// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui n1,n2,...,nk els nodes de T' en el recorregut en postordre de T'.
//       Llavors, n1 guarda el valor 1, n2 guarda el valor 2, ..., nk guarda el valor k.
BinTree<int> postorderTree(BinTree<int> t){
    // Tengo un árbol.
    // Necesito obtener el postorden de ese árbol.
    // Entonces necesito crear un nuevo árbol en que cada hoja sea la posición
    // de ese valor en el posorden
    int counter = 1;
    // counter para ir contando 
    BinTree<int> newTree;
    postorderTree(t, newTree, counter);
    return newTree;
}


