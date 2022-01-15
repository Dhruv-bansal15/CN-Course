#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#include<bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int i=k;
    while(i<n){
        int ele = pq.top();
        if(ele>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }
    vector<int> v(k);
    i=k-1;
    while(i>=0){
        int ele= pq.top();
        v[i]=ele;
        pq.pop();
        i--;
    }
    return v;
    
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}