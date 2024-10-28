#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(){
    unordered_map<string, int> comptes;
    set<string> vermells;
    string ordre;
    while(cin >> ordre){
        if (ordre=="TRANSACTION"){
            string nom;
            int quantitat;
            cin >> nom >> quantitat;
            comptes[nom]+=quantitat;
            if (comptes[nom]<0) vermells.insert(nom);
            else if (comptes[nom]>=0) vermells.erase(nom);
        }
        else if (ordre=="NUMBERINRED"){
            cout << vermells.size() << endl;
        }
        else if (ordre=="PEOPLEINRED"){
            for (const auto& elem : vermells){
                cout << elem << " ";
            }
            cout << endl;
        }
    }
}