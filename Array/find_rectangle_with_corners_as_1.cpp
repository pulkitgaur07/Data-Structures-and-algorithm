// Question : Given an n x m binary matrix mat[][] containing only 0s and 1s, determine if there exists a rectangle within the matrix such that all four corners of the rectangle are 1. If such a rectangle exists, return true; otherwise, return false.

// Example:

// Input: mat[][] =
// [[1, 0, 0, 1, 0],
// [0, 0, 1, 0, 1],
// [0, 0, 0, 1, 0], 
// [1, 0, 1, 0, 1]] 
// Output: true
// Explanation: Valid corners are at index (1,2), (1,4), (3,2), (3,4) 
// Input: mat[][] =
// [[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
// Output: false
// Explanation: There are no valid corners.
// Constraints:
// 1 <= n, m <= 200
// 0 <= mat[i] <= 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ValidCorner(vector<vector<int> >& mat) {
        vector<vector<int>>vec;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    for(int k=j+1;k<mat[i].size();k++){
                        if(mat[i][k]==1){
                            vec.push_back({i,j,k});
                        }
                    }
                }
            }
        }
        for(int k=0;k<vec.size();k++){
            int i=vec[k][0];
            int j1=vec[k][1];
            int j2=vec[k][2];
            for(int idx=i+1;idx<mat.size();idx++){
                if(mat[idx][j1]==1 && mat[idx][j2]==1)
                return true;
            }
        }
        return false;
    }
};