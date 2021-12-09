#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char getchar(string s){
    int num = s[0] - '0';
    if(s.length()==2)
    	num = 10*(s[0] - '0') + s[1] - '0';
    char ans=  'a' + num - 1;
    return ans;
}

void getcode(string input,string s){
    if(input.length()==0){
        cout<<s<<endl;
        return;
    }
    if(input.length()==1){
        char aa = getchar(input.substr(0,1));
        s.push_back(aa);
        cout<<s<<endl;
        return;
    }
    char aa = getchar(input.substr(0,1));
    getcode(input.substr(1) , s+aa);
    if(input.length()>1)
    {
        int num = 10*(input[0] - '0') + (input[1] - '0');
        if(num >=10 && num<=26)
        {
            char aa = getchar(input.substr(0,2));
            getcode(input.substr(2),s+aa);
        }

    }
    return;
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    getcode(input,"");
}


using namespace std;

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
