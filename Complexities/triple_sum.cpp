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
int tripletSum(int *arr, int n, int num)
{
	int i, j, k;
 	int cnt=0;
    sort(arr, arr + n);
 
    for (i = 0; i < n - 2; i++){
        j = i + 1;
        k = n - 1;
        while(j<k){
        	if(arr[i] + arr[j] + arr[k]>num){
            	k--;
        	}else if(arr[i] + arr[j] + arr[k] <num){
        	    j++;
        	}else{
        	    if(arr[j]==arr[k]){
         	       cnt+= nCr(k-j+1,2);
         	   }else{
                int cnt1=0,cnt2=0;
                int a=arr[j],b=arr[k];
                while(arr[j]==a & j<n){
                    cnt1++;
                    j++;
                }
                while(arr[k]==b & k>i){
                    cnt2++;k--;
                }
                cnt+= cnt1*cnt2;
            }
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}