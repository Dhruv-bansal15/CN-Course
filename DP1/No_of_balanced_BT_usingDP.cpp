#include <iostream>
using namespace std;
#include <cmath>

int helper(int h, int* arr){
    if(h<=1){
        return 1;
    }
    if(arr[h]!=-1){
        return arr[h];
    }
    int mod = (int)pow(10,9) + 7;
    int x = helper(h-1,arr);
    int y = helper(h-2,arr);
    int temp1 = ((long)(x) * x)%mod;
    int temp2 = (2*(long)(x)*y)%mod;
    int ans= (temp1 + temp2)%mod;
    arr[h]= ans;
    return ans;
}

int balancedBTs(int n) {
    // Write your code here
    int arr[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    return helper(n,arr);
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}