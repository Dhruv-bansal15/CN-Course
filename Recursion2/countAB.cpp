#include <iostream>
#include <string>
using namespace std;
bool check(char input[], string s){
    if(s==""){
        if(input[0]=='a'){
            bool ans = check(input+1,"a");
            return ans;
        }else{
            return false;
        }
    }else if(s=="a"){
        if(input[0]=='\0'){
            return true;
        }else if(input[0]=='a'){
            bool ans = check(input+1,"a");
            return ans;
        }else if(input[0]=='b' & input[1]=='b'){
            bool ans = check(input+2,"bb");
            return ans;
        }else{
            return false;
        }
    }else if(s=="bb"){
        if(input[0]=='\0'){
            return true;
        }else if(input[0]=='a'){
            bool ans = check(input+1,"a");
            return ans;
        }else{
            return false;
        }
    }
}

bool checkAB(char input[]) {
	// Write your code here
    string ss="";
    return check(input, ss);

}




using namespace std;

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
