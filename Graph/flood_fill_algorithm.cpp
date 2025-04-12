// Question : You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

// Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

// Examples:

// Input: image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2

// Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]

// Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].
// Input: image[][] = [[1, 1, 1], [1, 1, 0], [1, 0, 1]], sr = 1, sc = 1, newColor = 2
// Output: [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
// Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Input: image[][] = [[0, 1, 0], [0, 1, 0]], sr = 0, sc = 1, newColor = 0
// Output: [[0, 0, 0], [0, 0, 0]]
// Explanation: Starting from pixel (0, 1) with value 1, flood fill changes all 4-directionally connected pixels with value 1 to 0, resulting in [[0, 0, 0], [0, 0, 0]]
// Constraints:
// 1 ≤ n ≤ m ≤ 500
// 0 ≤ image[i][j] ≤ 10
// 0 ≤ newColor ≤ 10
// 0 ≤ sr ≤ (n-1)
// 0 ≤ sc ≤ (m-1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row,int col,int clr,vector<vector<int>> &vis,vector<vector<int>> &image,
    vector<vector<int>> &ans, int dr[],int dc[],int n,int m,int newColor){
        vis[row][col] = 1;
        ans[row][col] = newColor;
        for(int i=0;i<4;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol] == clr){
                dfs(nrow,ncol,clr,vis,image,ans,dr,dc,n,m,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
        int n = image.size();
        int m = image[0].size();
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans = image;
        dfs(sr,sc,image[sr][sc],vis,image,ans,dr,dc,n,m,newColor);
        return ans;
    }
};