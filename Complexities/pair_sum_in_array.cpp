#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int fact(int n){
    int res=1;
    for(int i=2;i<=n;i++)
        res = (res*i);
    return res;
}
int nCr(int n,int r){
    return fact(n)/ (fact(r)*fact(n-r));
}
int pairSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr+0,arr+n);
    int cnt=0,i=0,j=n-1;
    while(i<j){
        if(arr[i] + arr[j]>num){
            j--;
        }else if(arr[i] + arr[j]<num){
            i++;
        }else{
            if(arr[i]==arr[j]){
                cnt+= nCr(j-i+1,2);
            }else{
                int cnt1=0,cnt2=0;
                int a=arr[i],b=arr[j];
                while(arr[i]==a & i<n){
                    cnt1++;
                    i++;
                }
                while(arr[j]==b & j>=0){
                    cnt2++;j--;
                }
                cnt+= cnt1*cnt2;
            }
        }
    }
    return cnt;
    
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}