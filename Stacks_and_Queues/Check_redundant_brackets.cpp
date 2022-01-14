#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    int n= expression.size();
    stack<char> s;
    for(int i=0;i<n;i++){
        if(expression[i]==')'){
            int cnt=0;
            while(s.top()!= '('){
                cnt++;
                s.pop();
            }
            s.pop();
            if(cnt<=1){
                return true;
            }
        }else{
            s.push(expression[i]);
        }
    }
    return false;
    
    
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}