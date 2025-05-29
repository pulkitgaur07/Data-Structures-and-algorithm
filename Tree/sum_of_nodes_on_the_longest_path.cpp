// Question : Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

// Examples:

// Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
// Output: 13
// Explanation:

// The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
// Input: root[] = [1, 2, 3, 4, 5, 6, 7]

// Output: 11
// Explanation: 

// The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
// Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

// Output: 19
// Explanation: 

// The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
// Constraints:
// 1 <= number of nodes <= 106
// 0 <= node->data <= 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    
    int ans = 0;

    void dfs(Node* root,int sum,int len,int &maxi){
        if(!root){
            if(len>maxi){
                maxi = len;
                ans = sum;
            }
            else if(len==maxi){
                ans = max(ans,sum);
            }
            return;
        }
        sum += root->data;
        dfs(root->left,sum,len+1,maxi);
        dfs(root->right,sum,len+1,maxi);
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        if(!root) return 0;
        int maxi = 0;
        dfs(root,0,1,maxi);
        return ans;
    }
};