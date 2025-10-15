// Question : Given the root of a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.

// Examples:

// Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3
    
// Output: 10
// Explanation: 10 is the 3rd smallest element in the BST.
// Input: root = [2, 1, 3], k = 5
    
// Output: -1
// Explanation: There is no 5th smallest element in the BST as the size of BST is 3.
// Constraints:
// 1 ≤ number of nodes, k ≤ 104
// 1 ≤ node->data ≤ 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void dfs(Node* root,vector<int>&ans){
        if(!root){
            return;
        }
        dfs(root->left,ans);
        ans.push_back(root->data);
        dfs(root->right,ans);
    }
    int kthSmallest(Node *root, int k) {
        vector<int>ans;
        dfs(root,ans);
        return k>ans.size() ? -1 : ans[k-1];
    }
};