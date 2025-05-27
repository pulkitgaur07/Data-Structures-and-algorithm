// Question : Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


// Examples:

// Input: preorder[] = [5, 2, 10]
// Output: [2, 10]
// Explaination: 

// 2 and 10 are the leaf nodes as shown in the figure.
// Input: preorder[] = [4, 2, 1, 3, 6, 5]
// Output: [1, 3, 5]
// Explaination: 

// 1, 3 and 5 are the leaf nodes as shown in the figure.
// Input: preorder[] = [8, 2, 5, 10, 12]
// Output: [5, 12]
// Explaination: 

// 5 and 12 are the leaf nodes as shown in the figure.

// Constraints:
// 1 ≤ preorder.size() ≤ 103
// 1 ≤ preorder[i] ≤ 103

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> ans;
        stack<int> st;
        st.push(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            if(preorder[i] < st.top()){
                st.push(preorder[i]);
            }else{
                int temp = st.top();
                int cnt = 0;
                while(!st.empty() && preorder[i] > st.top()){
                    st.pop();
                    cnt++;
                }
                st.push(preorder[i]);
                if(cnt>=2){
                    ans.push_back(temp);
                }
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};