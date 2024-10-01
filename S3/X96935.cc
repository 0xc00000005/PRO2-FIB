#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool impar;
    if (n%2==0) impar=false;
    else impar=true;
    bool palindrom = true;
    stack<int> pila;
    for (int i=0; i<(n/2); i++){
        int a;
        cin >> a;
        pila.push(a);
    }
    if (impar){
        int c;
        cin >> c;
    }
    for (int i=0; i<(n/2); i++){
        int a = 0;
        cin >> a;
        if (a!=pila.top()) palindrom=false;
        pila.pop();
    }
    if(palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;
}