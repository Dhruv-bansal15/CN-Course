#include <iostream>
using namespace std;
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int output[n];
    output[0]=1;
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                int temp = output[j] + 1;
                if(output[i]<temp){
                    output[i]=temp;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(output[i]>ans){
            ans= output[i];
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}