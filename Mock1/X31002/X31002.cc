#include <iostream>
#include <list>
#include <string>

using namespace std;

void processList(std::list<char>& frase) {
    for (auto it = frase.begin(); it != frase.end(); ) {
        auto prev_it = it;
        if (prev_it != frase.begin()) {
            --prev_it;
            if ((*it - *prev_it) == ('A' - 'a') || (*it - *prev_it) == ('a' - 'A')) {
                it = frase.erase(it); // Erase current element and get the next iterator
                it = frase.erase(prev_it); // Erase previous element
                continue; // Skip incrementing the iterator
            }
        }
        ++it; // Move to the next element
    }
}

int main() {
    string input;
    while(cin >> input){
        list<char> frase;
        for (int i=0; i<input.size(); ++i) frase.push_back(input[i]);
        processList(frase);
        for (char c : frase) {
            cout << c;
        }
        cout << endl;
}
}