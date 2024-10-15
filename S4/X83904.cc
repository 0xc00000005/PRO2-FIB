#include <iostream>
#include <set>
#include <map>

using namespace std;

void readmap(map<string, int> &m){
  string s;
  while (cin >> s && s != ".") {
    m[s];
  }
}

void readset(set<string> &set7){
  string s;
  while (cin >> s && s != ".") {
    set7.insert(s);
  }
}

void updatemap(map<string, int> &m, set<string> &set7){
  // Iterates through the set of players.
  for(set<string>::iterator it = set7.begin(); it != set7.end(); ++it){
    // *it is the value in the set. 
    // m.find returns an iterator, which is itmap.
    map<string, int>::iterator itmap = m.find((*it));
    // We desreference it to access the count and add 1.
    (*itmap).second++;
  }
}

void printmap(map<string, int> &m, int n){
  cout << "Totes les activitats:";
  for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
    if((*it).second == n) cout << ' ' << (*it).first;
  }
  cout << endl;
  
  cout << "Cap activitat:";
  for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
    if((*it).second == 0) cout << ' ' << (*it).first;
  }
  cout << endl;
}

int main(){
  // Map m contains the players.
  map<string, int> m;
  readmap(m);
  
  int n; cin >> n;
  // A loop is created for each activity.
  for (int i = 0; i < n; ++i) {
    set<string> set7;
    // Players are saved in set7.
    readset(set7);
    // The map is updated with the players in set7.
    // If they are already in the map, their value is increased by 1.
    updatemap(m,set7);
  }
  
  printmap(m,n);
}