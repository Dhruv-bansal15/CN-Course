#include<bits/stdc++.h>
using namespace std;
int grid[9][9];


bool findEmptyPos(int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                row=i,col=j;
                return true;
            }
        }
    }
    return false;
}

bool isPossRow(int row,int value){
    for(int i=0;i<9;i++){
        if(grid[row][i]==value){
            return false;
        }
    }
    return true;
}
bool isPossCol(int col,int value){
    for(int i=0;i<9;i++){
        if(grid[i][col]==value){
            return false;
        }
    }
    return true;
}
bool isPossGrid(int row,int col, int value){
    int rowF = row - (row%3);
    int colF = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowF][j+colF]==value){
                return false;
            }
        }
    }
    return true;
}
bool isPossible(int row, int col, int value){
    if(isPossRow(row,value) && isPossCol(col,value) && isPossGrid(row,col,value)){
        return true;
    }
    return false;
}
bool solveSoduku(){
    int row,col;
    if(!findEmptyPos(row,col)){
        return true;
    }
    
    for(int i=1;i<=9;i++){
        if(isPossible(row,col,i)){
            grid[row][col]=i;
            bool ans = solveSoduku();
            if(ans){
                return true;
            }else{
                grid[row][col]=0;
            }
        }
    }
    return false;
    
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int x;cin>>x;
            grid[i][j]=x;
        }
    }
    bool ans = solveSoduku();
    if(ans==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}