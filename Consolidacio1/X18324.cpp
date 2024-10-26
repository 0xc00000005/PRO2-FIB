#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']');
}

int main() {
    string input;
    while (cin >> input) {
        stack<int> pila;
        int maxLength = 0;
        int lastValidIndex = -1;

        for (int i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c == '(' || c == '[') {
                pila.push(i);
            } else if (c == ')' || c == ']') {
                if (!pila.empty() && isMatchingPair(input[pila.top()], c)) {
                    pila.pop();
                    if (pila.empty()) {
                        // Si la pila está vacía, la secuencia es válida desde lastValidIndex hasta i
                        maxLength = max(maxLength, i - lastValidIndex);
                    } else {
                        // Si la pila no está vacía, la secuencia válida está entre el último elemento de la pila y i
                        maxLength = max(maxLength, i - pila.top());
                    }
                } else {
                    // Si no hay un par válido, actualizamos el índice del último carácter no válido
                    lastValidIndex = i;
                }
            }
        }

        cout << maxLength << endl;
    }
}
