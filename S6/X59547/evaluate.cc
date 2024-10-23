#include "BinTree.hh"
#include "evaluate.hh"
#include "utils.hh"


int evaluate(map<string,int> &variable2value, BinTree<string> t){
    int value=0;
    if(!t.empty()){
        if(!isNumber(t.value()) && !isVariable(t.value())){
            if (t.value()=="*"){
                value = evaluate(variable2value, t.left()) * evaluate(variable2value, t.right());
            }
            else if (t.value()=="+"){
                value = evaluate(variable2value, t.left()) + evaluate(variable2value, t.right());
            }
            else if (t.value()=="-"){
                value = evaluate(variable2value, t.left()) - evaluate(variable2value, t.right());
            }
        }
        else{
            if (!isVariable(t.value())) value = mystoi(t.value());
            else value=variable2value[t.value()];
            
        }
    }
    return value;
}
