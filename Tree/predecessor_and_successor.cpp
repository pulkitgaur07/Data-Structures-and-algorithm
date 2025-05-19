// Question : You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

// Examples :

// Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

// Output: 4 9
// Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
// Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

// Output: 10 -1
// Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
// Input: root[] = [2, 1, 3], key = 3

// Output: 2 -1
// Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
// Constraints: 
// 1 <= no. of nodes <= 105
// 1 <= node->data <= 106
// 1 <= key <= 106

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* pre(Node* root, int k){
        Node* pred = NULL;
        Node* curr = root;
        while(curr != NULL){
            if(k <= curr->data){
                curr = curr->left;
            }else{
                pred = curr;
                curr = curr->right;
            }
        }
        return pred;
    }
    
    Node* suc(Node* root, int k){
        Node* succ = NULL;
        Node* curr = root;
        while(curr != NULL){
            if(k >= curr->data){
                curr = curr->right;
            }else{
                succ = curr;
                curr = curr->left;
            }
        }
        return succ;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        if(!root){
            return {NULL, NULL};
        }
        return {pre(root, key), suc(root, key)};
    }
};