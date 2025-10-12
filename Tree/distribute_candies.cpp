// Question : You are given the root of a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.

// The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy.

// Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

// Examples:

// Input: root = [5, 0, 0, N, N, 0, 0]
  
// Output: 6
// Explanation:
// Move 1 candy from root to left child
// Move 1 candy from root to right child
// Move 1 candy from right child to root->right->left node
// Move 1 candy from root to right child
// Move 1 candy from right child to root->right->right node
// Move 1 candy from root to right child
// so, total 6 moves required.
// Input: root = [2, 0, 0, N, N, 3, 0]
  
// Output: 4
// Explanation:
// Move 1 candy from root to left child
// Move 1 candy from root->right->left node to root->right node
// Move 1 candy from root->right node to root->right->right node
// Move 1 candy from root->right->left node to root->right node
// so, total 4 moves required.
// Constraints:
// 1 ≤ n ≤ 3*103
// 0 ≤ Node->data ≤ n
// The sum of all Node->data = n

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int moves = 0;
    int dfs(Node* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        moves += abs(left) + abs(right);
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};