#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int>* getPath(int** edges,int n,int sv,int ev)
{
    if(sv==ev){
        vector<int>* output = new vector<int>();
        output->push_back(sv);
        return output;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(sv);
    int arr[n+1];
    arr[sv]=-1;
    visited[sv]=true;
    bool done=false;
    while(!q.empty()){
        if(done==true){
            break;
        }
        int curr = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i==curr){
                continue;
            }else if(edges[curr][i]==1 && !visited[i]){
                arr[i]=curr;
                q.push(i);
                visited[i]=true;
                if(i==ev){
                    done=true;
                    break;
                }
            }
            
        }
    }
    if(done==false){
        return NULL;
    }else{
        
        vector<int>* output = new vector<int>();
        output->push_back(ev);
        while(arr[ev]!=-1){
            output->push_back(arr[ev]);
            ev = arr[ev];
        }
        
        return output;
    }
    
    
    
}

int main() {
    // Write your code here
     int v,e;
    cin>>v>>e;
    int **edges = new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i] = new int[v];
        for(int j=0;j<v;j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i = 0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int sv,ev;
    cin>>sv>>ev;
    vector<int>* output = getPath(edges,v,sv,ev);
    
    if(output!=NULL)
    {
        for(int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" ";
        }
        delete output;
    }
   
    for(int i=0;i<v;i++)
    {
        delete [] edges[i];
    }
}