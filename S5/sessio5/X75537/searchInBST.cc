#include "BinTree.hh"
#include "searchInBST.hh"

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t
bool searchInBST(BinTree<int> t, int x){
    bool found=false;
    if (!t.empty()){
        if (t.value()==x) return true;
        // else found=(searchInBST(t.left(),x) || searchInBST(t.right(),x));
        else{
            if (t.value()>x) found=(searchInBST(t.left(),x));
            else if (t.value()<x) found=(searchInBST(t.right(),x));
        }
    } 
    return found;
}