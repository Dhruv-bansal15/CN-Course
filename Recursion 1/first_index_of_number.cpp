#include<iostream>
int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size==1){
        return (input[0]==x ? 0 : -1);
    }
    
    if(input[0]==x){
        return 0;
    }
    int ans = firstIndex(input+1,size-1,x);
    return (ans==-1 ? -1 : 1 + ans);

}

using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}


