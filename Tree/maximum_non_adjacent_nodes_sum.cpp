// Question : Given the root of a binary tree with integer values. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

// Examples:

// Input: root = [11, 1, 2]

// Output: 11
// Explanation: The maximum sum is obtained by selecting the node 11.

// Input: root = [1, 2, 3, 4, N, 5, 6]

// Output: 16
// Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5 and 6, which are not directly connected to each other. Their total sum is 16.  

// Constraints:
// 1 ≤ number of nodes ≤ 104
// 1 ≤ node.data ≤ 105

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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    pair<int,int>solve(Node* root){
        if(!root) return make_pair(0,0);
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        pair<int,int>ans;
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first,left.second) + max(right.first,right.second);
        return ans;
    }
    int getMaxSum(Node *root) {
        pair<int,int>ans;
        ans = solve(root);
        return max(ans.first,ans.second);
    }
};