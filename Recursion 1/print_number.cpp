#include<iostream>
using namespace std;
void print(int n){
    if(n == 1){
        cout << n << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
    return;
}

int main(){
    int n;
    cin >> n;
  
    print(n);
}



