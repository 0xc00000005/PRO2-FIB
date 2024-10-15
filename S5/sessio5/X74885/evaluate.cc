#include "BinTree.hh"
#include "evaluate.hh"
#include "utils.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(BinTree<string> t){
    int value=0;
    if(!t.empty()){
        if(!isNumber(t.value())){
            if (t.value()=="*"){
                value = evaluate(t.left()) * evaluate(t.right());
            }
            else if (t.value()=="+"){
                value = evaluate(t.left()) + evaluate(t.right());
            }
            else if (t.value()=="-"){
                value = evaluate(t.left()) - evaluate(t.right());
            }
        }
        else{
            value = mystoi(t.value());
        }
    }
    return value;
}
