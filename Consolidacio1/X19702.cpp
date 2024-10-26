#include <list>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    list<int> v;
    string command;
    int index=0;

    while (cin >> command) {
        if (command == "index++;") {
            index++;
        } 
        else if (command == "index--;") {
            index--;
        } 
        else if (command == "v.push_front(") {
            int number;
            cin >> number;
            v.push_front(number);
            string ending;
            cin >> ending; // Això consumeix el ");"

        } 
        else if (command == "v.push_back(") {
            int number;
            cin >> number;
            //cout << number << endl;
            v.push_back(number);
            string ending;
            cin >> ending; // Això consumeix el ");"

        }       
        else if (command == "v.insert(index,") {
            list<int>::iterator it2 = v.begin();
            for(int i=0; i<index; i++){
                ++it2;
            }
            int number;
            cin >> number;
            v.insert(it2, number);
            string ending;
            cin >> ending; // Això consumeix el ");"

        } 
        else if (command == "cout<<v[index]<<endl;") {
            list<int>::iterator it = v.begin();
            if (index==0) cout << *it << endl;
            else{
            for(int i=0; i<index; i++){
                ++it;
            }
            cout << *it << endl;
            }
        }
    }
}