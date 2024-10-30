#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

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
            cout << "maxLenght " << maxLength << endl;
            char c = input[i];
            if (c == '(' || c == '[') {
                pila.push(i);
            } else if (c == ')' || c == ']') {
                if (!pila.empty() && isMatchingPair(input[pila.top()], c)) {
                    pila.pop();
                    if (pila.empty()) {
                        maxLength = max(maxLength, i - lastValidIndex);
                    } else {
                        maxLength = max(maxLength, i - pila.top());
                    }
                } else {
                    // Reset the last valid index to the current position
                    lastValidIndex = i;
                    // Clear the stack as the sequence is invalid
                    while (!pila.empty()) {
                        pila.pop();
                    }
                }
            }
        }

        cout << maxLength << endl;
    }
    return 0;
}