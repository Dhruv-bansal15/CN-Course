#include <iostream>
int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n==1 | n==0){
        return 1;
    }
    int ans1=0,ans2=0,ans3=0;
    if(n>=1){
        ans1 = staircase(n-1);
    }
    if(n>=2){
        ans2 = staircase(n-2);
    }
    if(n>=3){
        ans3 = staircase(n-3);
    }
    return ans1+ans2+ans3;   
}
using namespace std;

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
