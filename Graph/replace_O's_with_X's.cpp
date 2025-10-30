// Question : You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Examples:

// Input: 
// grid[][] = [['X', 'X', 'X', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'O', 'O', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'X', 'O', 'O']]
// Output: 
// [['X', 'X', 'X', 'X'], 
// ['X', 'X', 'X', 'X'], 
// ['X', 'X', 'X', 'X'], 
// ['X', 'X', 'X', 'X'], 
// ['X', 'X', 'O', 'O']]
// Explanation: We only changed those 'O' that are surrounded by 'X'
// Input: 
// grid[][] = [['X', 'O', 'X', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'O', 'O', 'X'], 
//           ['X', 'O', 'X', 'X'], 
//           ['X', 'X', 'O', 'O']]
// Output: 
// [['X', 'O', 'X', 'X'], 
// ['X', 'O', 'X', 'X'], 
// ['X', 'O', 'O', 'X'], 
// ['X', 'O', 'X', 'X'], 
// ['X', 'X', 'O', 'O']]
// Explanation: There's no 'O' that's surround by 'X'.
// Input: 
// grid[][] = [['X', 'X', 'X'], 
//           ['X', 'O', 'X'], 
//           ['X', 'X', 'X']]
// Output: 
// [['X', 'X', 'X'], 
// ['X', 'X', 'X'], 
// ['X', 'X', 'X']]
// Explanation: There's only one 'O' that's surround by 'X'.
// Constraints:
// 1 ≤ grid.size() ≤ 100
// 1 ≤ grid[0].size() ≤ 100

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int row,int col,int n,int m,vector<vector<char>>&grid, vector<vector<int>>&vis,int dr[],int dc[]){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O'){
                dfs(nrow,ncol,n,m,grid,vis,dc,dr);
            }
        }
    }
    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 'O'){
                dfs(i,0,n,m,grid,vis,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1] == 'O'){
                dfs(i,m-1,n,m,grid,vis,dr,dc);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j] == 'O'){
                dfs(0,j,n,m,grid,vis,dr,dc);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[n-1][j] && grid[n-1][j] == 'O'){
                dfs(n-1,j,n,m,grid,vis,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
            }
        }
    }
};