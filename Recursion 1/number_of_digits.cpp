#include<iostream>
int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}
using namespace std;


int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


