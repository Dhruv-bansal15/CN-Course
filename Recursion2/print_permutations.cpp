#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


void print(string input,string s){
    if(input.length()==0){
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<input.length();i++){
        char ch = input[i];
        string left_substr = input.substr(0,i);
        string right_substr = input.substr(i+1);
        string rest = left_substr + right_substr;
        print(rest , s+ch);
    }
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    print(input,"");
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}