#include <iostream>
#include <vector>
using namespace std;
void initialize(bool **visited,int N,int M){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}
bool dfs(vector<vector<char>> &Graph,char c[],int i,int j,int N,int M,bool ** visited){
    
    if(Graph[i][j]=='A')
        return true;
    
    visited[i][j]=true;
    bool ans=false;
    
    if(i-1>=0 && j-1>=0 && Graph[i-1][j-1]==c[0] && !visited[i-1][j-1])
        ans=ans || dfs(Graph,c+1,i-1,j-1,N,M,visited);
    
    if(ans==false){
        if(i-1>=0 && Graph[i-1][j]==c[0] && !visited[i-1][j])
        	ans=ans || dfs(Graph,c+1,i-1,j,N,M,visited);
    }
    if(ans==false){
        if(i-1>=0 && j+1<M && Graph[i-1][j+1]==c[0] && !visited[i-1][j+1])
        	ans=ans || dfs(Graph,c+1,i-1,j+1,N,M,visited);
    }
    if(ans==false){
        if(j+1<M && Graph[i][j+1]==c[0] && !visited[i][j+1])
        	ans=ans || dfs(Graph,c+1,i,j+1,N,M,visited);
    }
    if(ans==false){
        if(i+1<N && j+1<M && Graph[i+1][j+1]==c[0] && !visited[i+1][j+1])
        	ans=ans || dfs(Graph,c+1,i+1,j+1,N,M,visited);
    }
    if(ans==false){
        if(i+1<N && Graph[i+1][j]==c[0] && !visited[i+1][j])
        	ans=ans || dfs(Graph,c+1,i+1,j,N,M,visited);
    }
    if(ans==false){
        if(i+1<N && j-1>=0 && Graph[i+1][j-1]==c[0] && !visited[i+1][j-1])
        	ans=ans || dfs(Graph,c+1,i+1,j-1,N,M,visited);
    }
    if(ans==false){
        if(j-1>=0 && Graph[i][j-1]==c[0] && !visited[i][j-1])
        	ans=ans || dfs(Graph,c+1,i,j-1,N,M,visited);
    } 
    visited[i][j]=false;
    return ans;
}


bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    char c[]="CODINGNINJA";
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
    }
    
    initialize(visited,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool ans=false;
            if(board[i][j]=='C'){
                ans=dfs(board,c+1,i,j,n,m,visited);
                if(ans)
                    return 1;
                
            }
        }
    }
    
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}