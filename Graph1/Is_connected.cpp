#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bfs_disconnected(int** edges, int n){
    queue<int> q;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        // cout<<curr<<" ";
        for(int i=0;i<n;i++){
            if(i==curr){
                continue;
            }
            if(edges[curr][i]==1 & !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
        
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;
    
}

int main() {
    // Write your code here
    int n,e;
    cin >> n >> e;

    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    bool ans = bfs_disconnected(graph,n);
    if(ans==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}