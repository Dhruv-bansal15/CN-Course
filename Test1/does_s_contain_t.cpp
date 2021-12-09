#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
using namespace std;
bool checksequenece(char large[] , char*small) {
	// int a = strlen(large);
	// int b = strlen(small);
    if((large[0]!='\0' | large[0]=='\0') && small[0]=='\0'){
        return true;
    }else if(large[0]=='\0' && small[0]!= '\0'){
        return false;
    }
    if(small[0]==large[0]){
        return checksequenece(large+1,small+1);
    }else{
        return checksequenece(large+1,small);
    }
}


int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
