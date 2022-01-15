#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if(n==0){
        return 0;
    }
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        int a = arr[i] + dp[i-2];
        int b = dp[i-1];
        dp[i] = max(a,b);
    }
    return dp[n-1];
    
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}