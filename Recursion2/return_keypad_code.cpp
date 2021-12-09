#include <iostream>
#include <string>
#include <string>
using namespace std;
#include <bits/stdc++.h>

string whatOnKeyboard(int n){
    if(n==1){
        return "";
    }else if(n==2){
        return "abc";
    }
    else if(n==3){
        return "def";
    }
    else if(n==4){
        return "ghi";
    }
    else if(n==5){
        return "jkl";
    }
    else if(n==6){
        return "mno";
    }
    else if(n==7){
        return "pqrs";
    }
    else if(n==8){
        return "tuv";
    }
    else if(n==9){
        return "wxyz";
    }
}
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    // 2359
    if(num==0){
        output[0]="";
        return 1;
    }
    int temp = num;
    int ele = num%10;
    int ans = keypad(num/10, output);
    
    string s = whatOnKeyboard(ele);
    int n = ans;
	string arr[n*(s.length())];
    int temp=0;
    for(int i=0;i<n;i++){
        string hihi = output[i];
        for(int j=0;j<s.length();j++){
            arr[temp] = hihi + s[j];
            temp++;
        }
    }
    for(int i=0;i<n*(s.length());i++){
        output[i]=arr[i];
    }
    return n*(s.length());
    
}

using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
