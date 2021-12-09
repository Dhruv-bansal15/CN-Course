#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int findDuplicate(int *arr, int n)
{
    //Write your code here
    int curr=0;
    for(int i=0;i<n;i++){
		curr+= arr[i];
    }
    long long int sum = (n-2)*(n-1);
    sum/=2;
    return curr-sum;
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}