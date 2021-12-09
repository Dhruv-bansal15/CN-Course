#include <iostream>
using namespace std;

void printsub(int input[],int size, int k, int st, int output[],int sizeo){
    if(size==0){
        if(k==0){
            for(int i=0;i<sizeo;i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    printsub(input,size-1,k,st+1,output,sizeo);
    output[sizeo] = input[st];
    printsub(input,size-1,k-input[st],st+1,output,sizeo+1);
    return;
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[20];
    printsub(input,size,k,0,output,0);
    return;
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
