#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root){
        queue<Node *> q;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int>temp;
            for (int i = 0; i < size; i++){
                Node *root = q.front();
                q.pop();
                temp.push_back(root->data);
                if (!root->left){
                    q.push(root->left);
                }
                if (root->right){
                    q.push(root->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};