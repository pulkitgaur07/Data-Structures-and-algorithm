// Question : You are given n courses, labeled from 0 to n - 1 and a 2d array prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.

// Find the ordering of courses we should take to complete all the courses.

// Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. The Driver code will print true if you return any correct order of courses else it will print false. 

// Examples:

// Input: n = 3, prerequisites[][] = [[1, 0], [2, 1]]
// Output: true
// Explanation: To take course 1, you must finish course 0. To take course 2, you must finish course 1. So the only valid order is [0, 1, 2].
// Input: n = 4, prerequisites[][] = [[2, 0], [2, 1], [3, 2]]
// Output: true
// Explanation: Course 2 requires both 0 and 1. Course 3 requires course 2. Hence, both [0, 1, 2, 3] and [1, 0, 2, 3] are valid.
// Constraints:
// 1 ≤ n ≤ 104
// 0 ≤ prerequisites.size() ≤ 105
// 0 ≤ prerequisites[i][0], prerequisites[i][1] < n
// All prerequisite pairs are unique
// prerequisites[i][0] ≠ prerequisites[i][1]

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(auto it : prerequisites){
            int x = it[0];
            int y = it[1];
            indegree[x]++;
            adj[y].push_back(x);
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

// Optimized Code by removing queue and grid

class Solution {
public:
    void dfs(int row,int col,int m,int n,vector<vector<int>> &vis){
        // traverse up
        for(int i=row-1;i>=0;i--){
            if(vis[i][col] == -2 || vis[i][col] == -1) break;
            vis[i][col] = 1;
        }
        // traverse down
        for(int i=row+1;i<m;i++){
            if(vis[i][col] == -2 || vis[i][col] == -1) break;
            vis[i][col] = 1;
        }
        // traverse left
        for(int j=col-1;j>=0;j--){
            if(vis[row][j] == -2 || vis[row][j] == -1) break;
            vis[row][j] = 1;
        }
        // traverse right
        for(int j=col+1;j<n;j++){
            if(vis[row][j] == -2 || vis[row][j] == -1) break;
            vis[row][j] = 1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(auto it : guards){
            int i = it[0];
            int j = it[1];
            vis[i][j] = -2;
        }
        for(auto it : walls){
            int i = it[0];
            int j = it[1];
            vis[i][j] = -1;
        }
        for(auto it : guards){
            int i = it[0];
            int j = it[1];
            dfs(i,j,m,n,vis);
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