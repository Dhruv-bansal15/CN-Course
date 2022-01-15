#include <iostream>
using namespace std;
using namespace std;
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(arr[i]-arr[j])==k){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}