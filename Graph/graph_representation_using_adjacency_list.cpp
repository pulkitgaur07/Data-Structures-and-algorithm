#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
    return 0;
}

// 1 Based Indexing.
// n -> number of nodes.
// m -> number of edges.
// Space -> (E)
// In weighted graph we put weight along with node using pair<int,int>