#include <iostream>
#include <stack>

using namespace std;
// El programa funciona con la premisa de que hay el mismo número de abiertos que de cerrados, y que
// el más reciente por fuerza tiene que cerrarse antes.
int main(){
    char c;
    int n=0;
    int a=0;
    stack<char> s;
    bool mod=false;
    while(cin >> c and c != '.'){
        //cout << s.size() << endl;
        if(c == '(' or c == '['){
            s.push(c);
          //  cout << 'a' << endl;
            // Se almacenan los abiertos en la pila
        } else if(!s.empty() and ((c == ')' and s.top() == '(') or (c == ']' and s.top() == '['))){
            s.pop();
           // cout << 'b' << endl;

            // Si me das algo cerrado y hay abiertos en pila,se mira si se cierra y se borran.
        } else if(s.empty() and (c == ')' or c == ']')){
            s.push('.');
           // cout << 'c' << endl;

            c = '.';
            // Si no hay nada en la pila, se pone el punto, ya que es incorrecto.
        } else {
            if (!mod){
                n=(a+1);
                mod=true;
            }
           // cout << 'd' << endl;
            c = '.';
        }
        a++;
    }
    if (n==0) n=a;
    if(s.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte " << n << endl;
}