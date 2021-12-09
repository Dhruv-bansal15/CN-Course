#include <iostream>
using namespace std;
int length(char input[]){
    if(input[0]=='\0')
        return 0;
    int small = length(input+1);
    return small + 1;
}
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    if(length(input)==1 | length(input)==0){
        return;
    }
    if(input[0]!=input[1]){
        removeConsecutiveDuplicates(input+1);
    }else{
        char ch = input[0];
        int i=0;
        while(input[i]==ch){
            i++;
        }
        int j=1;
        while(input[i]!='\0'){
            input[j]=input[i];
            j++,i++;
        }
        input[j]=input[i];
        removeConsecutiveDuplicates(input);
    }
    


}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}