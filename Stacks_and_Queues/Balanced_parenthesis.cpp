#include <iostream>
#include <string>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    int s=0;
    for(int i=0;i<expression.size();i++){
        if(expression[i]=='('){
            s++;
        }else if(expression[i]==')'){
            if(s>0){
             	s--;   
            }
            else {
               return false; 
            }
                
        }
    }
    if(s>0){
        return false;
    }
    return true;
    
    
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}