#include <iostream>
// Change in the given string itself. So no need to return or print the changed string.
#include <bits/stdc++.h>
void pairStar(char input[]) {
    // Write your code here
    int n = strlen(input);
    if(n==1){
        return;
    }
    
	pairStar(input+1);
    n= strlen(input);
    if(input[0]==input[1]){
        for(int i=n;i>=1;i--){
            input[i+1]=input[i];
        }
        input[1]='*';
    }
    return;

}

using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
