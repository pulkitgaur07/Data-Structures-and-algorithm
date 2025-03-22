// Question : You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int>&vis,int &cnt,int par){
        vis[node] = par;
        cnt++;
        for(auto it : adj[node]){
            if(vis[it] == -1){
                dfs(it,adj,vis,cnt,par);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }
        vector<int>vis(n,-1);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                int cnt = 0;
                dfs(i,adj,vis,cnt,i);
                int flag = 1;
                for(int j=0;j<n;j++){
                    if(vis[j] == i){
                        if(indegree[j] != (cnt-1)){
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
        return ans;
    }
};