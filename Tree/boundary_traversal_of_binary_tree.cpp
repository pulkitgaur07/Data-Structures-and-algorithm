// Question : Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
// 1. Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

// 2. Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

// 3. Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 


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
      void traverseLeft(Node* root, vector<int> &ans){
          if(!root || (!root->left && !root->right)){
              return;
          }
          ans.push_back(root->data);
          if(root->left) traverseLeft(root->left,ans);
          else traverseLeft(root->right,ans);
      }
      
      void traverseRight(Node* root, vector<int> &ans){
          if(!root || (!root->left && !root->right)){
              return;
          }
          if(root->right) traverseRight(root->right,ans);
          else traverseRight(root->left,ans);
          ans.push_back(root->data);
      }
      
      void traverseLeaf(Node* root, vector<int> &ans){
          if(!root) return;
          if(!root->left && !root->right){
              ans.push_back(root->data);
              return;
          }
          traverseLeaf(root->left,ans);
          traverseLeaf(root->right,ans);
      }
      
      vector<int> boundaryTraversal(Node *root) {
          vector<int>ans;
          if(!root) return ans;
          ans.push_back(root->data);
          traverseLeft(root->left,ans);
          traverseLeaf(root->left,ans);
          traverseLeaf(root->right,ans);
          traverseRight(root->right,ans);
          return ans;
      }
  };