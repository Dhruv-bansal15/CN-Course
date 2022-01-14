#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    stack<int> s;
    while(!input.empty()){
        int temp = input.front();
        input.pop();
        s.push(temp);
    }
    while(!s.empty()){
        input.push(s.top());
        s.pop();
    }
    return;
    
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}