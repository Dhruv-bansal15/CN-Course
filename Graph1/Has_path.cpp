#include <iostream>
#include <queue> 
using namespace std;

bool ifpath(int **edges, int n, int st, int end){
    if(st==end){
        return true;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> q;
    q.push(st);
    visited[st]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(edges[curr][end]==1){
            return true;
        }else{
            for(int i=0;i<n;i++){
                if(i==curr){
                    continue;
                }else if(edges[curr][i]==1 && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    return false;
    
}

int main() {
    // Write your code here
    int n,e;cin>>n>>e;
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int v1,v2;cin>>v1>>v2;
    
    if(ifpath(edges, n, v1, v2)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}