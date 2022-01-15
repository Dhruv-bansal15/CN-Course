#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int helper(string s1, string s2, int m, int n, int** output){
    if(m==0 | n==0){
        return max(m,n);
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }else if(s1[0]==s2[0]){
        return helper(s1.substr(1), s2.substr(1), m-1, n-1, output);
    }else{
        int x = helper(s1.substr(1),s2, m-1, n, output) + 1;
        int y = helper(s1,s2.substr(1), m, n-1, output) + 1;
        int z = helper(s1.substr(1),s2.substr(1), m-1, n-1, output) + 1;
        output[m][n]= min(x,min(y,z));
        return output[m][n];
    }
    
    
    
}

int editDistance(string s1, string s2)
{
	//Write your code here
    int m = s1.length();
    int n = s2.length();
    int** output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]= new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    return helper(s1,s2,m,n,output);
    
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}