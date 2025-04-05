// Question :
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Examples:

// Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
// Output: 4
// Explanation:
// The image below shows all the 4 islands in the grid.

// Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
// Output: 2
// Expanation:
// The image below shows 2 islands in the grid.

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] = {'L', 'W'}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Depth First Search

class Solution {
public:
    void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,int n,int m,int dr[],int dc[]){
        vis[row][col] = 1;
        for(int i=0;i<8;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                dfs(nrow,ncol,grid,vis,n,m,dr,dc);
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        int dr[8] = {-1,-1,-1,0,+1,+1,+1,0};
        int dc[8] = {-1,0,+1,+1,+1,0,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    ans++;
                    dfs(i,j,grid,vis,n,m,dr,dc);
                }
            }
        }
        return ans;
    }
};

// Using Breath First Search

class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,int n,int m,int dr[],int dc[]){
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        int dr[8] = {-1,-1,-1,0,+1,+1,+1,0};
        int dc[8] = {-1,0,+1,+1,+1,0,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    ans++;
                    bfs(i,j,grid,vis,n,m,dr,dc);
                }
            }
        }
        return ans;
    }
};