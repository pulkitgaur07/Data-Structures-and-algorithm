// Question : Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

// Examples:

// Input: root[] = [11, 1, 2]

// Output: 11
// Explanation: The maximum sum is obtained by selecting the node 11.

// Input: root[] = [1, 2, 3, 4, N, 5, 6]

// Output: 16
// Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

// Constraints:
// 1 ≤ no. of nodes in the tree ≤ 104
// 1 ≤ Node.val ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    pair<int,int> dfs(Node* root){
        if(!root)return {0,0};
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        return {root->data+l.second+r.second,max({l.first+r.first,l.second+r.second,
            l.first+r.second,r.first+l.second
        })};
    }

    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        auto ans=dfs(root);
        return max(ans.first,ans.second);
    }
};