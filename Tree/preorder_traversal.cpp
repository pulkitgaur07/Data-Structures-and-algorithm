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
    void preorder(Node* root, vector<int>&ans){
        if(!root){
            return;
        }
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    vector<int> preOrder(Node* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};