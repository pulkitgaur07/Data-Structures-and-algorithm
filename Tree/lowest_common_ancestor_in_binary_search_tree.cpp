// Question : Given a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST.

// LCA between two nodes n1 and n2 is defined as the lowest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).


#include <iostream>
#include <bits/stdc++.h>
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
      bool traverse(vector<Node*> &first,Node *root,Node *n){
          if(!root) return false;
          first.push_back(root);
          if(root==n) return true;
          if(traverse(first,root->left,n)||traverse(first,root->right,n)){
              return true;
          }
          first.pop_back();
          return false;
      }
      
      Node* LCA(Node* root, Node* n1, Node* n2) {
          vector<Node*> first;
          vector<Node*> second;
          traverse(first,root,n1);
          traverse(second,root,n2);
          
          int i;
          for( i=0;i<first.size()&&i<second.size();i++){
              if(first[i]!=second[i]) break;
          }
          return first[i-1];
      }
  };