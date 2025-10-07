// Question : You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, 6]
    
// Output: [4, 2, 5, 3, 6]
// Explanation: The Green nodes represent the bottom view of below binary tree.
    
// Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
// Output: [5, 10, 4, 28, 25]
// Explanation: The Green nodes represent the bottom view of below binary tree.
    
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        unordered_map<Node*,int>omap;
        map<int,vector<Node*>>mapForOrder;
        queue<Node*>q;
        q.push(root);
        omap[root]=0;
        mapForOrder[0].push_back(root);
        while(!q.empty()) {
            int counter=q.size();
            for(int i=0;i<counter;i++) {
                Node* vertex=q.front();
                q.pop(); 
                int location=omap[vertex];
                if(vertex->left!=NULL) {
                    q.push(vertex->left);
                    omap[vertex->left]=location-1;
                    mapForOrder[location-1].push_back(vertex->left);
                }
                if(vertex->right!=NULL) {
                    q.push(vertex->right);
                    omap[vertex->right]=location+1;
                    mapForOrder[location+1].push_back(vertex->right);
                }
            }
        }
        vector<int>ans;
        for(auto i:mapForOrder) {
            ans.push_back(i.second[i.second.size()-1]->data);
        }
        return ans;
    }
};