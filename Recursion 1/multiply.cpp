#include <iostream>
int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n==0){
        return 0;
    }
    int ans = multiplyNumbers(m,n-1);
    return ans + m;

}



using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
