#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=0;i<n;i++){
        int left = 2*i+1;
        int right=2*i+2;
        if(left<n){
            if(arr[left]>arr[i]){
                return false;
            }
        }
        if(right<n){
            if(arr[right]>arr[i]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}