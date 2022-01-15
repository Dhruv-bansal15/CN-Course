#include <cstring>
#include <string>
#include <iostream>
#include<algorithm>
using namespace std;
int editDistance(string s1, string s2) {
	// Write your code here
    if(s1.length()==0 || s2.length()==0){
        return max(s1.length(), s2.length());
    }
    
    if(s1[0]==s2[0]){
        return editDistance(s1.substr(1), s2.substr(1));
    }else{
        int x = editDistance(s1.substr(1),s2) + 1;
        int y = editDistance(s1,s2.substr(1)) + 1;
        int z = editDistance(s1.substr(1),s2.substr(1)) + 1;

        return min(x,min(y,z));
    }
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}