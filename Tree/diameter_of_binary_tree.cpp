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

int height(Node * root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left,maxi);
        int right = height(root->right,maxi);
        maxi= max(maxi,left+right);
        return max(left,right)+1;
    }


class Solution {
  public:
    int diameter(Node* node) {
        if(!node){
            return 0;
        }
        int ans = INT_MIN;
        height(node,ans);
        return ans;
    }
};