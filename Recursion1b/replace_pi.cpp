#include <iostream>
// Change in the given string itself. So no need to return or print anything
#include <bits/stdc++.h>
void replacePi(char input[]) {
	// Write your code here
    int n = strlen(input);
    if(n<=1){
        return;
    }
    
    replacePi(input+1);
    n = strlen(input);
    if(input[0]=='p' & input[1]=='i'){
        for(int i=n;i>=2;i--){
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    return;
	
}



using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
