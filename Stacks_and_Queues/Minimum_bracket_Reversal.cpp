#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here
    int n = input.length();
    if(n%2!=0){
        return -1;
    }
    stack<char> s;
    for(int i=0;i<n;i++){
        if(input[i]=='}' && !s.empty()){
            if(s.top()=='{'){
                s.pop();
            }else{
                s.push(input[i]);
            }
        }else{
            s.push(input[i]);
        }
    }
    int ff = s.size();
    int temp=0;
    while(!s.empty() & s.top()=='{'){
        temp++;
        s.pop();
    }
    return ff/2 + temp%2;
    
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}