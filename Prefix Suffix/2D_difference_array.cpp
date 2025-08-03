// Question : You are given a 2D integer matrix mat[][] of size n × m and a list of q operations opr[][]. Each operation is represented as an array [v, r1, c1, r2, c2], where:

// v is the value to be added
// (r1, c1) is the top-left cell of a submatrix
// (r2, c2) is the bottom-right cell of the submatrix (inclusive)
// For each of the q operations, add v to every element in the submatrix from (r1, c1) to (r2, c2). Return the final matrix after applying all operations.

// Examples:

// Input: mat[][] = [[1, 2, 3],  opr[][] = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]]
//                 [1, 1, 0],
//                 [4,-2, 2]]
// Output: [[3, 4, 3],
//         [2, 2, -1],
//         [3, -3, 1]] 
// Explanation: 
 
// Constraint:
// 1 ≤ n×m, q ≤ 105
// 0 ≤ r1 ≤ r2 ≤ n - 1
// 0 ≤ c1 ≤ c2 ≤ m - 1
// -104 ≤ mat[i][j], v ≤ 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<opr.size();i++){
            int v = opr[i][0];
            int r1 = opr[i][1];
            int c1 = opr[i][2];
            int r2 = opr[i][3];
            int c2 = opr[i][4];
            for(int j=r1;j<=r2;j++){
                ans[j][c1] += v;
                if(j == (n-1) && c2 == (m-1)) continue;
                if(c2 == (m-1)){
                    ans[j+1][0] -= v;
                }
                else{
                    ans[j][c2+1] -= v;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += ans[i][j];
                ans[i][j] = sum;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] += mat[i][j];
            }
        }
        return ans;
    }
};