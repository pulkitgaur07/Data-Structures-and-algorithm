// Question : Given a directed graph with V vertices numbered from 0 to V-1 and E directed edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents a directed edge from vertex u to vertex v. Return all Safe Nodes of the graph.
// A vertex with no outgoing edges is called a terminal node. A vertex is considered safe if every path starting from it eventually reaches a terminal node.

// Examples: 

// Input: V = 5, E = 6, edges[][] = [[1, 0], [1, 2], [1, 3], [1, 4], [2, 3], [3, 4]]

// Output: [0, 1, 2, 3, 4]
// Explanation: 4 and 0 is the terminal node, and all the paths from 1, 2, 3 lead to terminal node, i.e., 4.
// Input: V = 4, E = 3, edges[][] = [[1, 2], [2, 3], [3, 2]]

// Output: [0]
// Explanation: 0 is the terminal node, and no other node than 0 leads to 0.
// Constraints:
// 1 ≤ V ≤ 105
// 0 ≤ E ≤ 105
// 0 ≤ edges[i][0], edges[i][1] < V

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        vector<int>indegree(V,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};