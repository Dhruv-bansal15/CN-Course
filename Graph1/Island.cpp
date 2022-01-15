#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void BFS_helper(int** edges, int n, bool* visited, int st){
    queue<int> q;
    q.push(st);
    visited[st]=true;
    // vector<int> v;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        // v.push_back(curr);
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
    // sort(v.begin(), v.end());
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    return;
}

void bfs_print(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            BFS_helper(edges,n,visited,i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return;
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

    bfs_print(graph,n);
}