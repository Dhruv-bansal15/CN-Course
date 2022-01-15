#include<bits/stdc++.h>
using namespace std;
int chessboard[11][11];


bool isPossible(int n,int rowno, int colno){
    for(int i=rowno-1;i>=0;i--){
        if(chessboard[i][colno]==1){
            return false;
        }
    }
    for(int i=rowno-1,j=colno-1;i>=0 && j>=0;i--,j--){
        if(chessboard[i][j]==1){
            return false;
        }
    }
    for(int i=rowno-1,j=colno+1;i>=0 && j<n;i--,j++){
        if(chessboard[i][j]==1){
            return false;
        }
    }
    return true;
    
}
void helper(int n, int rowno){
    if(rowno==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<chessboard[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        if(isPossible(n,rowno,i)){
            chessboard[rowno][i]=1;
            helper(n,rowno+1);
            chessboard[rowno][i]=0;
        }
    }
    return;
}
void printNQueens(int n){
    memset(chessboard,0,11*11*sizeof(int));
    helper(n,0);
    return;
}
int main(){
    
    // write your code here
    int n;cin>>n;
    printNQueens(n);
    
    return 0;
}