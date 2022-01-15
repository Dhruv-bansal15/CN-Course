#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_vertex(int* weights, bool* visited, int n){
	int ans=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (ans==-1 || weights[i]<weights[ans])){
            ans=i;
        }
    }
    return ans;
}


void prim_algo(int** edges, int n){
    int* parent = new int[n];
    bool* visited = new bool[n];
    int* weights = new int[n];
    for(int i=0;i<n;i++){
        visited[i]= false;
        weights[i]= INT_MAX;
    }
    parent[0]=-1, weights[0]=0;
    
    for(int i=0;i<n;i++){
        int mini_vertex = min_vertex(weights, visited, n);
        visited[mini_vertex]=true;
        for(int j=0;j<n;j++){
            if(edges[mini_vertex][j]!=0 && weights[j]>edges[mini_vertex][j] && !visited[j]){
                parent[j]=mini_vertex;
                weights[j] = edges[mini_vertex][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
        }
    }
    return;
}

int main() {
    // Write your code here
    int n,e;cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b,w;cin>>a>>b>>w;
        edges[a][b] = w;
        edges[b][a]=w;
    }
    cout<<endl;
    prim_algo(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete[] edges;
}