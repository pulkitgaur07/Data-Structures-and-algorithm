// Question : Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.


// A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

// Examples:

// Input: root[] = [1, 2, 2, 3, 4, 4, 3]
//    ex-1_1
// Output: True
// Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.
// Input: root[] = [1, 2, 2, N, 3, N, 3]
//    ex-2_1
// Output: False
// Explanation:  As the left and right half of the above tree is not the mirror image, tree is not symmetric. 
// Constraints:
// 1  ≤ number of nodes ≤ 2000

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool issym(Node *left, Node* right){
        if(left==NULL || right== NULL)
        return left==right;
        
        if(left->data !=right->data){
            return false;
        }
        return issym(left->left, right->right)&& issym(left->right,right->left);
    }
    
    bool isSymmetric(Node* root) {
        return root == NULL|| issym(root->left, root->right);
    }
};