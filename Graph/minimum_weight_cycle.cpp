// Question : Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
// Your task is to find the minimum weight cycle in this graph.

// Examples:

// Input: V = 5, edges[][] = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]

// Output: 6
// Explanation: 

// Minimum-weighted cycle is  0 → 1 → 4 → 0 with a total weight of 6(2 + 1 + 3)
// Input: V = 5, edges[][] = [[0, 1, 3], [1, 2, 2], [0, 4, 1], [1, 4, 2], [1, 3, 1], [3, 4, 2], [2, 3, 3]]

// Output: 5
// Explanation: 

// Minimum-weighted cycle is  1 → 3 → 4 → 1 with a total weight of 5(1 + 2 + 2)
// Constraints:
// 1 ≤ V ≤ 100
// 1 ≤ E = edges.size() ≤ 103 
// 1 ≤ edges[i][j] ≤ 100

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dijkstra(int src, int dest, int V, vector<vector<int>>adj[]){
        vector<int>dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        dist[src]=0;
        while(!pq.empty()){
            auto &it=pq.top();
            int node=it.second;
            int d=it.first;
            pq.pop();
            
            for(auto& it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if((node==src && adjN==dest) || (node==dest && adjN==src)) continue;
                if(d+adjW<dist[adjN]){
                    dist[adjN]=d+adjW;
                    pq.push({dist[adjN], adjN});
                }
            }
        }
        
        return dist[dest];
    }
    int findMinCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int mini=1e9;
        for(int i=0; i<edges.size(); i++){
            int dist=(dijkstra(edges[i][0], edges[i][1], V, adj));
            if(dist!=1e9){
                mini=min(mini, dist+edges[i][2]);
            }
        }
        return mini;
    }
};