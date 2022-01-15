#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int i=k;
    while(i<n){
        int ele = pq.top();
        if(ele<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }
    vector<int> v(k);
    i=0;
    while(i<k){
        int ele= pq.top();
        v[i]=ele;
        pq.pop();
        i++;
    }
    return v[0];
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}