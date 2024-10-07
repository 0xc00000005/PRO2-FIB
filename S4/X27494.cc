#include <iostream>
#include <list>

using namespace std;

int minimum(list<int>& elements){
    int min = elements.front();
    if (elements.size() == 0) return 0;
    for (list<int>::iterator it = elements.begin(); it != elements.end(); it++){
        if (*it < min) min = *it;
    }
    return min;
}
int maximum(list<int>& elements){
    int max = elements.front();
    if (elements.size() == 0) return 0;
    for (list<int>::iterator it = elements.begin(); it != elements.end(); it++){
        if (*it > max) max = *it;
    }
    return max;
}
double average(list<int>& elements){
    double sum = 0;
    if (elements.size() == 0) return 0;
    for (list<int>::iterator it = elements.begin(); it != elements.end(); it++){
        sum += *it;
    }
    return sum/elements.size();
}

void remove(list<int>& elements, int num){
    for (list<int>::iterator it = elements.begin(); it != elements.end(); it++){
        if (*it == num){
            elements.erase(it);
            break;
        }
    }
}

int main(){
    list<int> elements;
    int code=0;
    int num=0;
    while (cin >> code){
        if (code == -1){
            cin >> num;
            elements.push_back(num);
            cout << minimum(elements) << " " << maximum(elements) << " " << average(elements) << endl;
        }
        else if (code == -2){
            cin >> num;
            remove(elements, num);
            cout << minimum(elements) << " " << maximum(elements) << " " << average(elements) << endl;
        }
        else if (code == 0) break;
    }
}