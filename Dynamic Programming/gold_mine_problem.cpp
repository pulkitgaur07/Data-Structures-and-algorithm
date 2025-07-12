// Question : Given a gold mine called mat[][]. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially, the miner can start from any row in the first column. From a given cell, the miner can move -

// to the cell diagonally up towards the right
// to the right
// to the cell diagonally down towards the right
// Find out the maximum amount of gold that he can collect until he can no longer move.

// Examples:

// Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
// Output: 12
// Explaination: The path is (1, 0) -> (2, 1) -> (2, 2). Total gold collected is 2 + 6 + 4 = 12.
// Input: mat[][] = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
// Output: 16
// Explaination: The path is (2, 0) -> (3, 1) -> (2, 2) -> (2, 3) or (2, 0) -> (1, 1) -> (1, 2) -> (0, 3). 
// Total gold collected is (5 + 6 + 2 + 3) or (5 + 2 + 4 + 5) = 16.
// Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
// Output: 14
// Explaination: The path is (1,0) -> (2,1) -> (2,2). Total gold collected is 2 + 7 + 5 = 14.
// Constraints:
// 1 ≤ mat.size(), mat[0].size() ≤ 500
// 0 ≤ mat[i][j] ≤ 100

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dfs(int i,int j, int n, int m, vector<vector<int>>&mat,vector<vector<int>> &dp){
        if(i >=n || i<0 || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int du = mat[i][j] + dfs(i-1,j+1,n,m,mat,dp);
        int r = mat[i][j] + dfs(i,j+1,n,m,mat,dp);
        int dd = mat[i][j] + dfs(i+1,j+1,n,m,mat,dp);
        return dp[i][j] = max({du,r,dd});
    }
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            ans = max(ans,dfs(i,0,n,m,mat,dp));
        }
        return ans;
    }
};