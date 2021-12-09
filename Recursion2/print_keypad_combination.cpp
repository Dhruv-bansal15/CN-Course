#include <iostream>
#include <string>
#include <iostream>
#include <string>
using namespace std;
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
void printkey(int num, string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    string s = whatOnKeyboard(num%10);
    int n = s.length();
    for(int i=0;i<n;i++){
        printkey(num/10, s[i] + output);
    }
    return;
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    printkey(num,output);
}

using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
