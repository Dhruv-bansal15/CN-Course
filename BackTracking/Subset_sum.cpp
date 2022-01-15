#include<bits/stdc++.h>
using namespace std;

int howManySubset(vector<int> a,int n, int sum){
    if(sum==0){
        return 1;
    }
    int tab[n + 1][sum + 1];
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
    for (int i = 1; i <= n; i++)
        tab[i][0] = 1;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum 
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
  
  
    return tab[n][sum];
    
}
int main(){
    
    // write your code here
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            arr.push_back(x);
        }
        int ans = howManySubset(arr,n,k);
        cout<<ans<<endl;
    }
    return 0;
}