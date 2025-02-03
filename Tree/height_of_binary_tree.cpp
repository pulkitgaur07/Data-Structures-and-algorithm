#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int heightOfBinaryTree(Node* node){
    if(!node){
        return 0;
    }
    int left = heightOfBinaryTree(node->left);
    int right = heightOfBinaryTree(node->right);
    int ans = max(left,right)+1;
    return ans;
}


class Solution {
  public:
    int height(Node* node) {
        if(!node){
            return 0;
        }
        int ans = heightOfBinaryTree(node);
        return ans;
    }
};