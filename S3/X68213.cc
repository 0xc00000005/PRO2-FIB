#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void menystres(stack<string> v, const int& c){
    cout << "Pila de la categoria " << c << endl;
    int d = v.size();
    for (int i=0; i<d; ++i){
        cout << v.top() << endl;
        v.pop();
    }
    cout << endl;
}


int main(){
    int n;
    int c;
    string titulo;
    cin >> n;
    vector<stack<string>> v(n);
    while(cin >> n && n!=(-4)){
        if(n==(-1)){
            cin >> titulo;
            cin >> c;
            v[c-1].push(titulo);
        }
        else if(n==(-2)){
            int q;
            cin >> q;
            cin >> c;
            for(int i=0; i<q; ++i){
                v[c-1].pop();
            }
        }
        else if(n==(-3)){
            cin >> c;
            if (v[c-1].empty()) cout << "Pila de la categoria " << c << endl << endl;
            else menystres(v[c-1], c);
        }
    }
}