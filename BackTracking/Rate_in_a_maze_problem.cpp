#include<bits/stdc++.h>
using namespace std;
int maze[18][18];
int solution[18][18];


void printsoln(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}

void printAllPath(int n, int row, int col){
    if(row>=n || col>=n || row<0 || col<0 || maze[row][col]==0 || solution[row][col]==1){
        return;
    }else if(row==n-1 && col==n-1){
        solution[row][col]=1;
        printsoln(n);
        solution[row][col]=0;
        return;
    }
    solution[row][col]=1;
    printAllPath(n,row-1,col);
    printAllPath(n,row+1,col);
    printAllPath(n,row,col-1);
    printAllPath(n,row,col+1);
    solution[row][col]=0;
    return;
    
    return;
}
int main() {
	// Write your code here
    int n;cin>>n;
    memset(solution,0,18*18*sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;cin>>x;
            maze[i][j]=x;
        }
    }
    printAllPath(n,0,0);
    
	return 0;
}
