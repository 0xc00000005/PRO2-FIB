#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "BinTree.hh"
using namespace std;

typedef BinTree<int> BT;

BT crear_arbol(const vector<int>& in, const vector<int>& pos, int& posIndex, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    // Si el rango es invalido, retornar un árbol vacío
    // Es decir, ya no hay más nodos que procesar
    if (inStart > inEnd) return BT();
    // Obtener el valor de la raiz actual desde pos usando posIndex
    int raiz = pos[posIndex--];
    // Encontrar la posicion de la raiz en el vector in usando inMap
    int inIndex = inMap[raiz];
    // Construir el subarbol derecho primero, luego el izquierdo
    BT right = crear_arbol(in, pos, posIndex, inIndex + 1, inEnd, inMap);
    // Al estar posIndex apuntado por REFERENCIA, se consumen todos los elementos del subarbol derecho
    // antes de pasar al subarbol izquierdo, como especifica el posorden.
    // El mismo concepto se aplica en las llamadas recursivas, con un indice cada vez menor.
    BT left = crear_arbol(in, pos, posIndex, inStart, inIndex - 1, inMap);
    // Crear el árbol con la raíz y los subárboles izquierdo y derecho
    return BT(raiz, left, right);
}

BT construir_arbol(const vector<int>& in, const vector<int>& pos) {
    // Posicion raiz en posOrden
    int posIndex = pos.size() - 1;
    // Se crea un mapa que realaciona valor de inorden con su posicion
    // El vector no se usa para acceder a los valores, sino para delimitar inStart, inEnd.
    unordered_map<int, int> inMap;
    for (int i = 0; i < in.size(); ++i) {
        // inMap[valor]= posicion
        inMap[in[i]] = i;
    }
    return crear_arbol(in, pos, posIndex, 0, in.size() - 1, inMap);
}

int main() {
    string format;
    cin >> format;
    int n;
    string tempp;
    getline(cin, tempp);
    while (cin >> n) {
        vector<int> postordre(n);
        vector<int> inordre(n);
        for (int i = 0; i < n; ++i) {
            cin >> inordre[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> postordre[i];
        }
        // Post: el inordre i el postordre es troben ordenats en el vector.
        BT t = construir_arbol(inordre, postordre);
        t.setOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT : BT::VISUALFORMAT);
        cout << t << endl;
    }
}