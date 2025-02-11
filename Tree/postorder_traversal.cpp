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
    void postorder(Node* root, vector<int>&ans){
        if(!root){
            return;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};