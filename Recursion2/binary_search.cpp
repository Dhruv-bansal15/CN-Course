#include <iostream>
// input - input array
// size - length of input array
// element - value to be searched
int binary(int input[],int st,int end,int ele){
    if(st>end){
        return -1;
    }
    int mid = (st+end)/2;
    if(input[mid]==ele){
        return mid;
    }else if(input[mid]<ele){
        return binary(input,mid+1,end,ele);
    }else{
        return binary(input,st,mid-1,ele);
    }
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    return binary(input,0,size-1,element);
}

using namespace std;

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
