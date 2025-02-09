// Question : Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

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
    int findMax(Node* root,int &ans){
        if(!root) return 0;
        int left = findMax(root->left,ans);
        int right = findMax(root->right,ans);
        int temp = max(0,max(left,right));
        ans = max(ans,max(root->data+left+right,root->data+temp));
        return root->data+temp;
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int ans = INT_MIN;
        findMax(root,ans);
        return ans;
    }
};