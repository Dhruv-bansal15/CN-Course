#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
bool helper(int* arr, int n, int start, int lsum, int rsum) 
{ 
    if (start == n) 
        return (lsum == rsum); 
    if (arr[start] % 5 == 0) 
        lsum += arr[start]; 
  
    else if (arr[start] % 3 == 0) 
        rsum += arr[start]; 
    else
        return (helper(arr, n, start + 1, lsum + arr[start], rsum) || helper(arr, n, start + 1, lsum, rsum + arr[start])); 
  
    // For cases when element is multiple of 3 or 5. 
    return helper(arr, n, start + 1, lsum, rsum); 
} 
bool splitArray(int *input, int size) {
    
    return helper(input, size, 0, 0, 0);
}

using namespace std;

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
