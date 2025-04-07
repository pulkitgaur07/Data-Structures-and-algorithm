// Question : Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

// Examples:
// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
// Output: true
// Explanation: 3 -> 3 is a cycle

// Input: V = 3, edges[][] = [[0, 1], [1, 2]]
// Output: false
// Explanation: no cycle in the graph

// Constraints:
// 1 ≤ V, E ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node,vector<int> &vis, vector<int> &path, vector<int> adj[]){
        vis[node] = 1;
        path[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,path,adj) == true){
                    return true;
                }
                else if (path[it]){
                    return true;
                }
            }
        }
        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>adj[V];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(V,0);
        vector<int>path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj) == true){
                    return true;
                }
            }
        }
        return false;
    }
};