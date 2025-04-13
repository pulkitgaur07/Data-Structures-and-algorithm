// Question : Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

// Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

// class Node {
//     val: integer
//     neighbors: List[Node]
// }
// Your task is to complete the function cloneGraph( ) which takes a starting node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

// Note: If you return a correct copy of the given graph, then the driver code will print true; and if an incorrect copy is generated or when you return the original node, the driver code will print false.

// Examples :

// Input: n = 4, adjList[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
// Output: true
// Explanation: 

// As the cloned graph is identical to the original one the driver code will print true.
// Input: n = 3, adjList[][] = [[1, 2], [0], [0]]
// Output: true
// Explanation: 

// As the cloned graph is identical to the original one the driver code will print true.
// Constraints:
// 1 ≤ n ≤ 104
// 0 ≤ no. of edges ≤ 105
// 0 ≤ adjList[i][j] < n

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> hash;
    unordered_map<Node*, bool> vis;
    
    void buildNode(Node* node) {
        if (!node) return;
        hash[node] = new Node(node->val);
        vis[node] = false;
        for (auto& i : node->neighbors) {
            if (hash.find(i) == hash.end()) {
                buildNode(i);
            }
        }
    }
    
    void dfs(Node* node){
        vis[node] = 1;
        for(auto it : node->neighbors){
            hash[node]->neighbors.push_back(hash[it]);
            if(!vis[it]){
                dfs(it);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        buildNode(node);
        dfs(node);
        return hash[node];
    }
};