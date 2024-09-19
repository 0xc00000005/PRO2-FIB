#include <vector>
#include <iostream>
#include "vectorIOint.hh"
using namespace std;
 
struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
{
    int max=v[0];
    int min=v[0];
 for(int i=0; i<v.size(); i++){
    if(v[i]<=min) min=v[i];
    if(v[i]>=max) max=v[i];
 }
 // Se crea otro parint para hacer el return;
 parint p {max, min};
 return p;
}
 
pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
{
    int max=v[0];
    int min=v[0];
  for(int i=0; i<v.size(); i++){
    if(v[i]<=min) min=v[i];
    if(v[i]>=max) max=v[i];
 }
 return make_pair(max, min);
}
 
void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
x=v[0];
y=v[0];
  for(int i=0; i<v.size(); i++){
    if(v[i]<=y) y=v[i];
    if(v[i]>=x) x=v[i];
 }
}


/* Leer vector
void leer_vector_int(vector<int>& v) {// version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<int> (numEst);
  
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i)
    cin >> v[i];
}*/

/* Escribir vector
void escribir_vector_int(const vector<int>& v) {
  for (int i=0; i<v.size();++i)
    cout << v[i] << " ";
  cout << endl;
}
*/
/*
int main(){
    vector<int> vect;
    leer_vector_int(vect);
    // Test 1
    parint p1;
    p1=max_min1(vect);
    cout << p1.prim << " " << p1.seg << endl; 
    // Test 2

    pair<int, int> p2;
    p2=max_min2(vect);
    cout << p2.first << " " << p2.second << endl;
    // Test 3
    int max=0;
    int min=0;
    max_min3(vect, max, min);
    cout << max << " " << min << endl;
}
*/
