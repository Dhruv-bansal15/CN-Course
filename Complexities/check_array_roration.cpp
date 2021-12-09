#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int arrayRotateCheck(int *arr, int size)
{
    //Write your code here
    bool done=false;
    int i;
    for(i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            done=true;
            break;
        }
    }
    if(done){
        return i+1;
    }else{
        return 0;
    }
    
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

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}