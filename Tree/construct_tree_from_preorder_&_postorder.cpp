// Question : Given two arrays pre[] and post[] that represent the preorder and postorder traversals of a full binary tree. Your task is to construct the binary tree and return its root.

// Note:  Full Binary Tree is a binary tree where every node has either 0 or 2 children. The preorder and postorder traversals contain unique values, and every value present in the preorder traversal is also found in the postorder traversal.

// Examples:

// Input: pre[] = [1, 2, 4, 8, 9, 5, 3, 6, 7], post[] = [8, 9, 4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
// Explanation: The tree will look like
   
// Input: pre[] = [1, 2, 4, 5, 3, 6, 7] , post[] = [4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7]
// Explanation: The tree will look like
   
// Constraints:
// 1 ≤ number of nodes ≤ 103
// 1 ≤ pre[i], post[i] ≤ 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    unordered_map<int, int> postIndex;
    int preIndex = 0;

    Node* build(vector<int>& pre, vector<int>& post, int start, int end) {
        if (preIndex >= pre.size() || start > end)
            return NULL;
        Node* root = new Node(pre[preIndex++]);
        if (start == end || preIndex >= pre.size())
            return root;
        int idx = postIndex[pre[preIndex]];
        root->left = build(pre, post, start, idx);
        root->right = build(pre, post, idx + 1, end - 1);

        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        for (int i = 0; i < n; i++){
            postIndex[post[i]] = i;
        }
        return build(pre, post, 0, n - 1);
    }
};