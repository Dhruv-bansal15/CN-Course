#include <iostream>
#include <math.h>
#include <iomanip>
double geometricSum(int k) {
    // Write your code here
    if(k==0){
        return 1;
    }
    double ans = geometricSum(k-1);
    int hihi = 1;
    for(int i=0;i<k;i++){
        hihi*=2;
    }
    return ans + 1/(double)hihi; 

}



using namespace std;

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
