#include <iostream>
using namespace std;


int helper(int x, int n, int num){
    int val = (x - pow(num, n));
    if (val == 0)
        return 1;
    if (val < 0)
        return 0;
 
    // Consider two possibilities, num is
    // included and num is not included.
    return helper(val, n, num + 1) + helper(x, n, num + 1);
}
int getAllWays(int a, int b) {
	// Write your code here
    
    return helper(a,b,1);
    
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}