#include <bits/stdc++.h>
using namespace std;

int helper(int **input,int m,int n, int mm, int nn){
    if(m==mm-1 & n== nn-1){
        return input[m][n];
    }
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;
    if(m+1<=mm-1){
        a = helper(input,m+1,n,mm,nn);
    }
    if(n+1<=nn-1){
        b = helper(input,m,n+1,mm,nn);
    }
    if(m+1<=mm-1 && n+1<=nn-1){
        c = helper(input,m+1,n+1,mm,nn);
    }
    int temp = min(a,min(b,c));
    return temp+input[m][n];
    
    
}

    

int minCostPath(int **input, int m, int n)
{
	//Write your code here
    return helper(input,0,0,m,n);
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}