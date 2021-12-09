#include <iostream>
#include <bits/stdc++.h>

bool fun(char input[],int s, int e){
    if (s == e)
    	return true;
    if (input[s] != input[e])
    	return false;
 
    if (s < e + 1)
    	return fun(input, s + 1, e - 1);
    return true;
}

bool checkPalindrome(char input[]) {
	int n = strlen(input);
    if (n == 0 | n==1)
        return true;
     
    return fun(input, 0, n - 1);
}

  2 3  

using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
