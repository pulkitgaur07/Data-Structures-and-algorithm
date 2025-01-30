#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

// 1 Based Indexing.
// n -> number of nodes.
// m -> number of edges.
// 1 -> Represent there is an edge between one vertex to another vertex.
// 0 -> Represent there is no any edge between one vertex to another vertex.
// In weighted graph we put weight instead 1.
// Space -> (N*N)