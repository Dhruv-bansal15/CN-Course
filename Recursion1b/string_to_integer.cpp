#include <iostream>
#include <bits/stdc++.h>
int stringToNumber(char input[]) {
    // Write your code here
    if (strlen(input) == 1)
        return (input[0] - '0');
 
    double y = stringToNumber(input+1);
    double x = input[0] - '0';
 
    // First digit multiplied by the
    // appropriate power of 10 and then
    // add the recursive result
    // For example, xy = ((x * 10) + y)
    x = x * pow(10, strlen(input) - 1) + y;
    return int(x);
}

using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
