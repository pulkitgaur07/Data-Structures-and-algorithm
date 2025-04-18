// Question : Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 
// 1 -> 2 -> 0 -> 1 is a cycle.

// Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
// Output: false
// Explanation: 
// No cycle in the graph.

// Constraints:
// 1 ≤ V ≤ 105
// 1 ≤ E = edges.size() ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int node,vector<int> adj[], vector<int> &vis){
        queue<pair<int,int>>q;
        q.push({node,-1});
        vis[node] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(it != par){
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};