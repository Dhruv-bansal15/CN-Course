#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_vertex(int* costs, bool* visited, int n){
	int ans=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (ans==-1 || costs[i]<costs[ans])){
            ans=i;
        }
    }
    return ans;
}


void djikstra_algo(int** edges, int n){
    bool* visited = new bool[n];
    int* costs = new int[n];
    for(int i=0;i<n;i++){
        visited[i]= false;
        costs[i]= INT_MAX;
    }
    costs[0]=0;
    for(int i=0;i<n;i++){
        int mini_vertex = min_vertex(costs, visited, n);
        visited[mini_vertex]=true;
        for(int j=0;j<n;j++){
            if(edges[mini_vertex][j]!=0 && !visited[j]){
                int temp = costs[mini_vertex] + edges[mini_vertex][j];
                if(temp<costs[j]){
                	costs[j] = temp;
                }
                
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<costs[i]<<endl;
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
    djikstra_algo(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete[] edges;
}