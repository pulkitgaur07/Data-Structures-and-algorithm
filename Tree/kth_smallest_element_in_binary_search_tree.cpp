// Question : Given a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void solve(Node* node, vector<int> &inorder){
        if(node==nullptr) return;
        solve(node->left, inorder);
        inorder.push_back(node->data);
        solve(node->right, inorder);
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        vector<int> inorder;
        solve(root,inorder);
        if(k<=inorder.size()) return inorder[k-1];
        else return -1;
    }
};