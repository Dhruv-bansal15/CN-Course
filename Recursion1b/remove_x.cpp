#include <iostream>
// Change in the given string itself. So no need to return or print anything
#include <bits/stdc++.h>
void removeX(char input[]) {
    // Write your code here
    int n = strlen(input);
    if(n==1){
        if(input[0]=='x'){
            input[0]=input[1];
        }
        return;
    }
    
    removeX(input+1);
    n = strlen(input); 
    if(input[0]=='x'){
        for(int i=0;i<n;i++){
            input[i]=input[i+1];
        }
    }
    return;

}

using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
