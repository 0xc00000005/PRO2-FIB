/*#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void calculate(queue<int> q) {
    int c = q.size();
    int min_val = q.front();
    int max_val = q.front();
    int sum = q.front();
    q.pop();
    while (!q.empty()) {
        int front = q.front();
        min_val = min(min_val, front);
        max_val = max(max_val, front);
        sum += front;
        q.pop();
    }
    double avg = (double)sum / c;
    cout << "min " << min_val << "; ";
    cout << "max " << max_val << "; ";
    cout << "media " << avg << endl;
}

int main() {
    int n;
    queue<int> q;
    while(cin >> n and (n<=100 && n>=(-1001))){
        if (n==(-1001) && !q.empty()) q.pop();
        else if (n!=(-1001)) q.push(n);
        if (!q.empty()) {
            calculate(q);
        } else if (q.empty()) cout << 0 << endl;
    }
}
*/
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct QueueStats {
    queue<int> q;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int sum = 0;

    void push(int val) {
        q.push(val);
        min_val = min(min_val, val);
        max_val = max(max_val, val);
        sum += val;
    }

    void pop() {
        if (!q.empty()) {
            int front = q.front();
            q.pop();
            if (front == min_val || front == max_val) {
                recalculate();
            } else {
                sum -= front;
            }
        }
    }

    void recalculate() {
        queue<int> temp = q;
        min_val = INT_MAX;
        max_val = INT_MIN;
        sum = 0;
        while (!temp.empty()) {
            int front = temp.front();
            min_val = min(min_val, front);
            max_val = max(max_val, front);
            sum += front;
            temp.pop();
        }
    }

    void print() {
        if (!q.empty()) {
            double avg = (double)sum / q.size();
            cout << "min " << min_val << "; ";
            cout << "max " << max_val << "; ";
            cout << "media " << avg << endl;
        } else {
            cout << 0 << endl;
        }
    }
};

int main() {
    int n;
    QueueStats qs;
    while(cin >> n and (n<=100 && n>=(-1001))){
        if (n==(-1001)) qs.pop();
        else if (n!=(-1001)) qs.push(n);
        qs.print();
    }
}