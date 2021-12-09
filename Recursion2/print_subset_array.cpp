#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void printsub(int input[],int size, int output[]){
    if(sizeof(input)/sizeof(input[0]) == 0){
        int n = sizeof(output)/sizeof(output[0]);
        for(int i=0;i<n;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int ele = input[0];
    printsub(input+1,size-1,output);
    int n = sizeof(output)/sizeof(output[0]);
    output[n]=ele;
    printsub(input+1,size-1,output);
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[16];
    printsub(input, size , output);
    return;
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
