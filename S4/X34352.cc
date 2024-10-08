#include <iostream>
#include <map>

using namespace std;

int frecuency(map<string, int>& d, string word){
    if (d.find(word) == d.end()) return 0;
    else return d[word];
}

int main(){
    char n;
    string p;
    map<string, int> diccionari;
    while (cin >> n){
        cin >> p;
        if (n == 'a'){
            diccionari[p]++;
        }
        if (n == 'f'){
            cout << frecuency(diccionari, p) << endl;
        }
    }
}
