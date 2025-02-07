#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
    };


class Solution {
public:
    void inorder(Node* root, vector<int>&ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};