#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int helper(int* weight, int* value, int n, int maxWeight, int** output){
    if(n==0 | maxWeight==0){
        return 0;
    }else if(weight[0] > maxWeight){
        if(output[n][maxWeight]!=-1){
            return output[n][maxWeight];
        }
        int ans = helper(weight+1,value+1,n-1,maxWeight, output);
        output[n][maxWeight]=ans;
        return ans;
    }
    if(output[n][maxWeight]!=-1){
        return output[n][maxWeight];
    }
    int a = helper(weight+1,value+1,n-1,maxWeight- weight[0], output) + value[0];
    int b = helper(weight+1,value+1,n-1,maxWeight, output);
    output[n][maxWeight] = max(a,b);
    return output[n][maxWeight];
    
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int** output = new int*[n+1];
    for(int i=0;i<=n;i++){
        output[i]= new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            output[i][j]=-1;
        }
    }
    return helper(weight,value,n,maxWeight, output);
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}