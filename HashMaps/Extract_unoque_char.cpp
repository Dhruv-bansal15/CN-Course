#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using namespace std;
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,bool> m;
    int n = str.length();
    string ans="";
    for(int i=0;i<n;i++){
        if(!m.count(str[i])>0){
            ans.push_back(str[i]);
            m[str[i]]=true;
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}