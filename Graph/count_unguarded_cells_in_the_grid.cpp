// Question : You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
// Return the number of unoccupied cells that are not guarded.

// Example 1:

// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.

// Example 2:

// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.

// Constraints:

// 1 <= m, n <= 105
// 2 <= m * n <= 105
// 1 <= guards.length, walls.length <= 5 * 104
// 2 <= guards.length + walls.length <= m * n
// guards[i].length == walls[j].length == 2
// 0 <= rowi, rowj < m
// 0 <= coli, colj < n
// All the positions in guards and walls are unique.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row,int col,int m,int n,vector<vector<int>> &vis,vector<vector<char>>&grid){
        vis[row][col] = 1;
        // traverse up
        for(int i=row-1;i>=0;i--){
            if(grid[i][col] == 'G' || grid[i][col] == 'W') break;
            vis[i][col] = 1;
        }
        // traverse down
        for(int i=row+1;i<m;i++){
            if(grid[i][col] == 'G' || grid[i][col] == 'W') break;
            vis[i][col] = 1;
        }
        // traverse left
        for(int j=col-1;j>=0;j--){
            if(grid[row][j] == 'G' || grid[row][j] == 'W') break;
            vis[row][j] = 1;
        }
        // traverse right
        for(int j=col+1;j<n;j++){
            if(grid[row][j] == 'G' || grid[row][j] == 'W') break;
            vis[row][j] = 1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>>grid(m,vector<char>(n));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(auto it : guards){
            int i = it[0];
            int j = it[1];
            grid[i][j] = 'G';
            q.push({i,j});
        }
        for(auto it : walls){
            int i = it[0];
            int j = it[1];
            vis[i][j] = 1;
            grid[i][j] = 'W';
        }
        while(!q.empty()){
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();
            dfs(row,col,m,n,vis,grid);
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};