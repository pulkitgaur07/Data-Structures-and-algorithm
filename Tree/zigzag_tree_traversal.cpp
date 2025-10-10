// Question : Given the root of a binary tree. You have to find the zig-zag level order traversal of the binary tree.
// Note: In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, and from right to left for even-numbered levels.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7]
// Output: [1, 3, 2, 4, 5, 6, 7]
// Explanation:
// Level 1 (left to right): [1]
// Level 2 (right to left): [3, 2]
// Level 3 (left to right): [4, 5, 6, 7]
// Final result: [1, 3, 2, 4, 5, 6, 7]
// Input: root = [7, 9, 7, 8, 8, 6, N, 10, 9]
// Output: [7, 7, 9, 8, 8, 6, 9, 10] 
// Explanation:
// Level 1 (left to right): [7]
// Level 2 (right to left): [7, 9]
// Level 3 (left to right): [8, 8, 6]
// Level 4 (right to left): [9, 10]
// Final result: [7, 7, 9, 8, 8, 6, 9, 10]
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool f = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0;i<size;i++){
                Node* front = q.front(); q.pop();
                v.push_back(front->data);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(f) reverse(v.begin(), v.end());
            f =!f;
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};