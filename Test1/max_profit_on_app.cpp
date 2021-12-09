#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(int budget[], int n) {
    // Write your code here
    sort(budget,budget+n);
    int ans=-1;
    // 14 20 30 53 
    for(int i=n-1;i>=0;i--){
        int temp = (budget[i])*(n-i);
        if(temp>ans){
            ans=temp;
        }
    }
    return ans;

}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
