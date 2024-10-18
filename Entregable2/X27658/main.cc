#include <iostream>
#include "BinTree.hh"
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;


typedef BinTree<int> BT;

void crear_arbol(BT &t, unordered_map<int, int> in, vector<int> pos) {
    if (pos.empty()) return;
    
    int raiz = pos.back();
    pos.pop_back();
    int index = in[raiz];
}

int main() {
    string format;
    cin >> format;
    int n;
    string tempp;
    getline(cin, tempp);
    string inordert;
    string postordert;
    while (cin >> n) {
        vector<int> postordre(n);
        unordered_map<int, int> inordre;
        for (int i = 0; i < n; ++i) {
            int value;
            cin >> value;
            inordre[value] = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> postordre[i];
        }
        // Post: el inordre i el postordre es troben ordenats en el unordered_map i el vector.
        BT t;
        
        t.setOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT : BT::VISUALFORMAT);
        cout << t << endl;
   }
}