#include <iostream>
#include <set>
#include <sstream>
#include <map>

using namespace std;

typedef map<string, set<string>> ML;

void matricula(ML &ea, ML &ae , string estudiant, string assignatura){
    ea[estudiant].insert(assignatura);
    ae[assignatura].insert(estudiant);
}

void anular(ML &ea, ML &ae , string estudiant, string assignatura){
    ea[estudiant].erase(assignatura);
    ae[assignatura].erase(estudiant);
}

void matricula_assignatura(ML &l, string assignatura){
    cout << assignatura << " tiene " << l[assignatura].size() << " alumnos" << endl;
}

void matricula_estudiant(ML &l, string estudiant){
    if (l[estudiant].empty()) cout << estudiant << " no tiene asignaturas matriculadas";
    else{
        cout << estudiant;
        for (const auto& assignatura : l[estudiant]) {
            cout << " " << assignatura;
        }
    }  
    cout << endl;
}

void final_assignatures(ML &l){
    // Pair no es lo mismo que std::pair, es simplemente un nombre de variable.
    // Igualmente std::map = std::pair<const Key, T>, por eso funciona .first y .second
    for (const auto& pair : l) {
        cout << pair.first << " " << pair.second.size() << endl;
    }
}

void final_estudiants(ML &l){
    for (const auto& pair : l) {
        if (!pair.second.empty()){
        cout << pair.first;
        // Se usa auto& para deducir el tipo de de elemento, y & para acceder por referencia
        // por motivos de eficiencia ya que son estructuras complejas
        for (const auto& assignatura : pair.second) {
            cout << " " << assignatura;
        }
        cout << endl;
        }
    }
}


int main(){
    int n;
    cin >> n;
    ML ae;
    ML ea;
    string temp1;
    
    for (int i=0; i<(n+1); ++i){
        string nomestudiant, nomasignatura;
        set<string> asignaturas;
        getline(cin, temp1);
        istringstream stream(temp1);
        stream >> nomestudiant;
        while(stream >> nomasignatura){
            asignaturas.insert(nomasignatura);
            ae[nomasignatura].insert(nomestudiant);
        }
        ea[nomestudiant]=asignaturas;
    }
    getline(cin, temp1);
    while(getline(cin, temp1) && temp1!="fin"){
        string ordre, variable;
        istringstream stream(temp1);
        stream >> ordre >> variable;
        if (ordre == "matricula"){
            string asi;
            stream >> asi;
            matricula(ea, ae, variable, asi);
        }
        if (ordre == "anular"){
            string asi;
            stream >> asi;
            anular(ea, ae, variable, asi);
        }
        if (ordre == "matricula_asignatura"){
            matricula_assignatura(ae, variable);
        }
        if (ordre == "matricula_estudiante"){
            matricula_estudiant(ea, variable);
        }
    }
    cout << endl;
    final_assignatures(ae);
    cout << endl;
    final_estudiants(ea);
    cout << endl;
}