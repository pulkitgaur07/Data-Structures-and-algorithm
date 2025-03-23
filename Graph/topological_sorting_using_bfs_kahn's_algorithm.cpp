// Topological Sorting

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

// The BFS based algorithm for Topological Sort is called Kahn’s Algorithm. The Kahn’s algorithm has same time complexity as the DFS based algorithm discussed above.

// Time Complexity: O(V+E). The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS
// Auxiliary space: O(V). The extra space is needed for the Indegree

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for(int i=0;i<V;i++){
            for(auto it : adj[V]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
};