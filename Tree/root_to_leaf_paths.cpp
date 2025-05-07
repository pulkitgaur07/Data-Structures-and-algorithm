// Question : Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5, N, N]
// ex-3
// Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
// Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3
// Input: root[] = [1, 2, 3]

// Output: [[1, 2], [1, 3]] 
// Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 and 1 -> 3
// Input: root[] = [10, 20, 30, 40, 60, N, N]

// Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
// Explanation: All the possible paths from root node to leaf nodes are: 10 -> 20 -> 40, 10 -> 20 -> 60 and 10 -> 30
// Constraints:
// 1 <= number of nodes <= 104
// 1 <= node->data <= 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void dfs(Node* root,vector<int>&path,vector<vector<int>>&ans){
        if(!root){
            return;
        }
        path.push_back(root->data);
        if(!root->left && !root->right){
            ans.push_back(path);
        }
        dfs(root->left,path,ans);
        dfs(root->right,path,ans);
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(root,path,ans);
        return ans;
    }
};