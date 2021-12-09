#include <iostream>
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
// int getstring(string input, int st, string output[10000],string s){
//     if(st== input.length()){
//         output[0]=s;
//         return 1;
//     }
//     string output1[10000];
//     int ans1 = getstring(input,st+1,output1,s);
//     char ch1 = getchar(input.substr(0,1));
//     for(int i=0;i<ans1;i++){
//         output[i] = ch1 + output1[i];
//     }
//     bool done=false;
//     if(st+1<input.length()){
//         string temp = input.substr(st,2);
//         if(10*(temp[0] - '0') + temp[1] - '0' <= 26){
//             done=true;
//             char ch2 = getchar(temp);
//             for(int i=0;i<ans1;i++){
//                 string ss = output[i];
//                 ss = ss.substr(1);
//                 output[i+ans1] = ch2 + ss;
//             }
//         }
//     }
//     return ans1 + ans1*(done==true);
// }
int getCodes(string input, string output[10000]) {
    
   	if(input.size()==0){
       output[0]="";
       return 1;
   	}
	if(input.size()==1){
        char aa = getchar(input.substr(0,1));
        // string hihihi(1,aa);
        output[0]=aa;
        return 1;
    }
    string result1[10000],result2[10000];
    int size2=0;

    int size1=getCodes(input.substr(1),result1);
    if(input.size()>1)
    {
        int num = 10*(input[0] - '0') + (input[1] - '0');
        if(num >=10 && num<=26)
        {
            size2=getCodes(input.substr(2),result2);
        }

    }
    int k=0;
    for(int i=0;i<size1;i++)
    {
        	char aa = getchar(input.substr(0,1));
        	// string hihihi(1,aa);
            output[k++]=aa + result1[i];
    }
    for(int i=0;i<size2;i++)
    {
        	char aa = getchar(input.substr(0,2));
        	// string hihihi(1,aa);
            output[k++]=aa + result2[i];
    }
    return k;
}

using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
