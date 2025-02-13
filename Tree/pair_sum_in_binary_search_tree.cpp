#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    unordered_map<int, int> map;

    bool preorder(Node *root, int target){

        if (root == NULL){
            return false;
        }
        if (map.find(target - root->data) != map.end()){
            return true;
        }
        map[root->data] = 1;
        if (preorder(root->left, target))
            return true;
        if (preorder(root->right, target))
            return true;

        return false;
    }

    bool findTarget(Node *root, int target){
        if (preorder(root, target)){
            return true;
        }
        return false;
    }
};