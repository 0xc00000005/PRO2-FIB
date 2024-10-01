#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<queue<string>> cues(n);
    queue<string> sortides;
    string nombres;
    string nombre;
    getline(cin, nombres);
    for(int i=0; i<n; ++i){
        getline(cin, nombres);
        istringstream stream(nombres);
        while (stream >> nombre){
         //   cout << "a " << nombre << endl;
            cues[i].push(nombre);
        }
    }
    string instruccio;
    int num=0;
    while (cin >> instruccio){
        if (instruccio=="SURT"){
            cin >> num;
            if(num>0 && num <=n) {
            sortides.push(cues[num-1].front());
            cues[num-1].pop();
            }
        }
        else if (instruccio=="ENTRA"){
            cin >> nombre;
            cin >> num;
            if(num>0 && num <=n) cues[num-1].push(nombre);
        }
    }
    cout << "SORTIDES" << endl << "--------" << endl;
    while (!sortides.empty()) {
        cout << sortides.front() << endl;
        sortides.pop();
    }
    cout << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    for (int a=0; a<n; ++a){
        cout << "cua " << a+1 << ": ";
        while(!cues[a].empty()){
            cout << cues[a].front() << " ";
            cues[a].pop();
        }
        cout << endl;
    }
}