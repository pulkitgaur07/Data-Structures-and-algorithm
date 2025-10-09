// Question : Given the root of a Binary Tree, your task is to return its Postorder Traversal.

// Note: A postorder traversal first visits the left child (including its entire subtree), then visits the right child (including its entire subtree), and finally visits the node itself.

// Examples:

// Input: root = [19, 10, 8, 11, 13]

// Output: [11, 13, 10, 8, 19]
// Explanation: The postorder traversal of the given binary tree is [11, 13, 10, 8, 19].
// Input: root = [11, 15, N, 7]
 
// Output: [7, 15, 11]
// Explanation: The postorder traversal of the given binary tree is [7, 15, 11].
// Constraints:
// 1 ≤ number of nodes ≤ 3*104
// 0 ≤ node->data ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void post(Node* root, vector<int>& ans){
        if (!root) return;
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }
};