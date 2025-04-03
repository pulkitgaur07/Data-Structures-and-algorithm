// Question : Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cell have fresh oranges
// 2 : Cell have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

// Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

// Examples:

// Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
// Output: 1
// Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.

// Input: mat[][] = [[2, 2, 0, 1]]
// Output: -1
// Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).

// Input: mat[][] = [[2, 2, 2], [0, 2, 0]]
// Output: 0
// Explanation: There is no fresh orange. 

// Constraints:
// 1 ≤ mat.size() ≤ 500
// 1 ≤ mat[0].size() ≤ 500
// mat[i][j] = {0, 1, 2} 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        int fresh = 0, rott = 0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    fresh++;
                }
                if(mat[i][j] == 2){
                    rott++;
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            ans = max(ans,tm);
            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    fresh--;
                    q.push({{nrow,ncol},tm+1});
                }
            }
        }
        if(fresh) return -1;
        return ans;
    }
};