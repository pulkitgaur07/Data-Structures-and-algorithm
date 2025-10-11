// Question : Given the root of a binary tree, your task is to find the maximum path sum. The path may start and end at any node in the tree.

// Examples:

// Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
// Output: 42
// Explanation: Max path sum is represented using green colour nodes in the above binary tree.

// Input: root[] = [-17, 11, 4, 20, -2, 10]
// Output: 31
// Explanation: Max path sum is represented using green colour nodes in the above binary tree.

// Constraints:
// 1 ≤ number of nodes ≤ 103
// -104 ≤ node->data ≤ 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
    int solve(Node* root, int &maxSum) {
        if (root == NULL)
            return 0;
        int left = max(0, solve(root->left, maxSum)); 
        int right = max(0, solve(root->right, maxSum));
        int currPathSum = root->data + left + right;
        maxSum = max(maxSum, currPathSum);
        return root->data + max(left, right);
    }
    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};