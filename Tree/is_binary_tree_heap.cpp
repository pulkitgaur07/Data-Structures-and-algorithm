// Question : You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

// A binary tree is considered a max-heap if it satisfies the following conditions:

// Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
// Max-Heap Property: The value of each node is greater than or equal to the values of its children.
// Examples:

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
// Output: true
// Explanation: The tree is complete and satisfies the max-heap property.

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
// Output: false
// Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.

// Constraints:
// 1 ≤ number of nodes ≤ 103
// 1 ≤ node->data ≤ 103

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Structure of node
class Node {
   public:
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
    bool isHeap(Node* tree) {
        if(tree == NULL) return true;
        queue<Node*> q;
        Node *root = tree;
        q.push(root);
        bool nullflag = false;
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(node == NULL) nullflag = true;
            else{
                if(nullflag==true) return false;
                if(node->left && node->left->data > node->data ||
                node->right && node->right->data > node->data) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};