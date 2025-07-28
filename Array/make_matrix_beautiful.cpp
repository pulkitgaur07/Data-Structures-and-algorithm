// Question : A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
// In one operation, you are allowed to increment the value of any single cell by 1.

// Examples:

// Input: mat[][] = [[1, 2], 
//                 [3, 4]]
// Output: 4
// Explanation:
// Increment value of cell(0, 0) by 3, 
// Increment value of cell(0, 1) by 1. 
// Matrix after the operations: [[4, 3], 
//                             [3, 4]]
// Here, sum of each row and column is 7.
// Hence total 4 operation are required.
// Input: mat[][] = [[1, 2, 3],
//                 [4, 2, 3],
//                 [3, 2, 1]]
// Output: 6
// Explanation: 
// Increment value of cell(0, 0) by 1, 
// Increment value of cell(0, 1) by 2, 
// Increment value of cell(2, 1) by 1, 
// Increment value of cell(2, 2) by 2. 
// Matrix after the operations: [[2, 4, 3], 
//                             [4, 2, 3],
//                             [3, 3, 3]] 
// Here, sum of each row and column is 9.
// Hence total 6 operation are required.
// Constraints:
// 1 ≤ mat.size() ≤ 900
// 0 ≤ mat[i][j] ≤ 106

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        int mx=INT_MIN,ans=0;
        for(int i=0;i<n;++i){
            int s1=0,s2=0;
            for(int j=0;j<n;++j){
                s1 += mat[i][j];
                s2 += mat[j][i];
            }
            mx=max(mx,max(s2,s1));
        }
        for(int i=0;i<n;++i){
            int s=0;
            for(int j=0;j<n;++j)
            s += mat[i][j];
            ans += (mx-s);
        }
        return ans;
    }
};