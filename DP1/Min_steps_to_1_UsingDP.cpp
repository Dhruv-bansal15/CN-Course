#include <bits/stdc++.h>
using namespace std;
int countStepsToOne(int n)
{
	//Write your code here
    int *arr = new int[n+1];
    arr[0]=0,arr[1]=0;
    if(n==1 | n==0){
        return arr[n];
    }
    for(int i=2;i<=n;i++){
    	int a = arr[i-1];
        int b=INT_MAX,c=INT_MAX;
        if(i%2==0){
            b = arr[i/2];
        }
        if(i%3==0){
            b = arr[i/3];
        }
        arr[i] = 1 + min(a,min(b,c));
    }
    return arr[n];
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}