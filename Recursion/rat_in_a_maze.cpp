// Question : Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.

// Examples:

// Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: maze[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell (1, 1) is blocked.
// Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.
// Constraints:
// 2 ≤ n ≤ 5
// 0 ≤ maze[i][j] ≤ 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int row,int col,int n,vector<vector<int>>&maze, vector<vector<int>>&vis,int dr[], int dc[], vector<string>&ans,string path){
        if(row == (n-1) && col == (n-1)){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<4;i++){
            int nr = row+dr[i];
            int nc = col+dc[i];
            if(nr >=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && maze[nr][nc] == 1){
                vis[nr][nc] = 1;
                if(dr[i] == -1 && dc[i] == 0){
                    dfs(nr,nc,n,maze,vis,dr,dc,ans,path+'U');
                }
                else if(dr[i] == 0 && dc[i] == 1){
                    dfs(nr,nc,n,maze,vis,dr,dc,ans,path+'R');
                }
                else if(dr[i] == 1 && dc[i] == 0){
                    dfs(nr,nc,n,maze,vis,dr,dc,ans,path+'D');
                }
                else{
                    dfs(nr,nc,n,maze,vis,dr,dc,ans,path+'L');
                }
                vis[nr][nc] = 0;
            }
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string>ans;
        if(maze[n-1][n-1] == 0){
            return ans;
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        vis[0][0]=1;
        dfs(0,0,n,maze,vis,dr,dc,ans,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};