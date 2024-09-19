#include "Estudiant.hh"
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<std::vector<Estudiant> > MatrixEstudiantes;

int main(){
    int m, n, s;
    cin >> m >> n >> s;
    vector<int> assignatures(s);
    for(int i=0; i<s; ++i){
        cin >> assignatures[i];
    }
    Matrixestudiantes mat(m, vector<Estudiant>(n));
    

}