// Question : Given a binary tree, convert the binary tree to its Mirror tree.
// Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.  


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
        left = right = NULL;
    }
};

class Solution {
  public:
    void mirror(Node* node) {
        if(!node) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
};