// Topological Sorting

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

// Example :
// Input : Edges - [[5,0],[5,2],[4,0],[4,1],[2,3],[3,1]]
// Output: 5 4 2 3 1 0
// Explanation: The first vertex in topological sorting is always a vertex with an in-degree of 0 (a vertex with no incoming edges).  A topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph. Another topological sorting of the following graph is “4 5 2 3 1 0”. 

// Topological Sorting vs Depth First Traversal (DFS): 
// In DFS, we print a vertex and then recursively call DFS for its adjacent vertices. In topological sorting, we need to print a vertex before its adjacent vertices. 

// For example, In the above given graph, the vertex ‘5’ should be printed before vertex ‘0’, but unlike DFS, the vertex ‘4’ should also be printed before vertex ‘0’. So Topological sorting is different from DFS. For example, a DFS of the shown graph is “5 2 3 1 0 4”, but it is not a topological sorting.

// Topological Sorting in Directed Acyclic Graphs (DAGs)
// DAGs are a special type of graphs in which each edge is directed such that no cycle exists in the graph, before understanding why Topological sort only exists for DAGs, lets first answer two questions:

// Why Topological Sort is not possible for graphs with undirected edges?
// This is due to the fact that undirected edge between two vertices u and v means, there is an edge from u to v as well as from v to u. Because of this both the nodes u and v depend upon each other and none of them can appear before the other in the topological ordering without creating a contradiction.


// Why Topological Sort is not possible for graphs having cycles?
// Imagine a graph with 3 vertices and edges = {1 to 2 , 2 to 3, 3 to 1} forming a cycle. Now if we try to topologically sort this graph starting from any vertex, it will always create a contradiction to our definition. All the vertices in a cycle are indirectly dependent on each other hence topological sorting fails.


// Topological order may not be Unique:
// -Topological sorting is a dependency problem in which completion of one task depends upon the completion of several other tasks whose order can vary. Let us understand this concept via an example:


// -Suppose our task is to reach our School and in order to reach there, first we need to get dressed. The dependencies to wear clothes is shown in the below dependency graph. For example you can not wear shoes before wearing socks.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
            dfs(it,adj,vis,st);
        }
        st.push(node);
    }
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};