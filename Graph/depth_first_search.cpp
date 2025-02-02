#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfsOfGraph(int node, vector<int>adj[], int vis[], vector<int>&ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfsOfGraph(it,adj,vis,ls);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n] = {0};
    int start = 0;
    vector<int>ls;
    dfsOfGraph(start,adj,vis,ls);
    for(int i=0;i<ls.size();i++){
        cout<<ls[i]<<" ";
    }
    cout<<endl;
    return 0;
}