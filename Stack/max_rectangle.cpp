// Question : You are given a 2D binary matrix mat[ ][ ], where each cell contains either 0 or 1. Your task is to find the maximum area of a rectangle that can be formed using only 1's within the matrix.

// Examples:

// Input: mat[][] = [[0, 1, 1, 0],
//                 [1, 1, 1, 1],
//                 [1, 1, 1, 1],
//                 [1, 1, 0, 0]]
// Output: 8
// Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
// [1, 1, 1, 1]
// [1, 1, 1, 1]
// and area is 4 * 2 = 8.
// Input: mat[][] = [[0, 1, 1],
//                 [1, 1, 1],
//                 [0, 1, 1]]
// Output: 6
// Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
// [1, 1]
// [1, 1]
// [1, 1]
// and area is 2 * 3 = 6.
// Constraints:
// 1 ≤ mat.size(), mat[0].size() ≤1000
// 0 ≤ mat[][] ≤1

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0;i<=n;i++){
            while(!st.empty() and (i==n or arr[i]<arr[st.top()])){
                int idx = st.top();
                st.pop();
            
                int l_idx  = (!st.empty()) ? st.top():-1;
                int r_idx = i;
                
                ans = max(ans, arr[idx]*(r_idx-l_idx-1));
            }
            st.push(i);
        }
        
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i-1>=0 and mat[i][j] == 1){
                    mat[i][j] += mat[i-1][j];
                }
            }
            ans = max(ans, getMaxArea(mat[i]));
        }
        
        return ans;
    }
};