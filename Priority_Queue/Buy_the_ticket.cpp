#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> max_heap;
    for(int i=0;i<n;i++){
        q.push(i);
        max_heap.push(arr[i]);
    }
    int cnt=0;
    while(!q.empty()){
        int a = q.front();
        int hihi = max_heap.top();
        if(arr[a]>=hihi){
            q.pop();
            cnt++;
            if(a==k){
                break;
            }
            if(arr[a]==hihi){
                max_heap.pop();
            }
        }else{
            q.pop();
            q.push(a);
        }
    }
    return cnt;
    
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}