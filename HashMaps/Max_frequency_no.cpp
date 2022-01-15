#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> m;
    int maxFreq = 0;
    for(int i = 0; i < n; i++){
        if(m.count(arr[i]) > 0){
            m[arr[i]]++;
            if(m[arr[i]] > maxFreq){
                maxFreq = m[arr[i]];
            }
        }else{
            m[arr[i]] = 1;
            if(m[arr[i]] > maxFreq){
                maxFreq = m[arr[i]];
            }
        }
        
    }
    for(int i = 0; i < n; i++){
        if(m[arr[i]] == maxFreq){
            return arr[i];
        } 
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}