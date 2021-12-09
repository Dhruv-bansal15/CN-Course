#include <iostream>

int countZeros(int n) {
    if(n/10 == 0){
        return (n==0 ? 1 : 0);
    }
    int ans = countZeros(n/10);
    if(n%10==0){
        return ans+1;
    }else{
        return ans;
    }
}



using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
