// Question : Given the root of a  BST with unique node values, transform it into greater sum tree where each node contains sum of all nodes greater than that node.

// Examples:

// Input: root = [11, 2, 29, 1, 7, 15, 40, N, N, N, N, N, N, 35, N]
      
// Output: [119, 137, 75, 139, 130, 104, 0, N, N, N, N, N, N, 40, N]
// Explanation: Every node is replaced with the sum of nodes greater than itself. 
      
// Input: root = [2, 1, 6, N, N, 3, 7]
     
// Output: [16, 18, 7, N, N, 13, 0]
// Explanation: Every node is replaced with the sum of nodes greater than itself. 
     
// Constraints :
// 1 ≤ node->data ≤ 3*104
// 1 ≤ number of nodes ≤ 3*104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int cs = 0;
    void transformTree(Node *root) {
        if(!root)return;
        int d = root->data;
        transformTree(root->right);
        root->data = cs;
        cs += d;
        transformTree(root->left);
    }
};