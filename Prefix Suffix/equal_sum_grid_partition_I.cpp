// Question : You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

// Each of the two resulting sections formed by the cut is non-empty.
// The sum of the elements in both sections is equal.
// Return true if such a partition exists; otherwise return false.

// Example 1:

// Input: grid = [[1,4],[2,3]]

// Output: true

// Explanation:

// A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

// Example 2:

// Input: grid = [[1,3],[2,4]]

// Output: false

// Explanation:

// No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

// Constraints:

// 1 <= m == grid.length <= 105
// 1 <= n == grid[i].length <= 105
// 2 <= m * n <= 105
// 1 <= grid[i][j] <= 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>row(n,0);
        vector<long long>col(m,0);
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=0;j<m;j++){
                sum += grid[i][j];
            }
            row[i] = sum;
        }
        for(int j=0;j<m;j++){
            long long sum = 0;
            for(int i=0;i<n;i++){
                sum += grid[i][j];
            }
            col[j] = sum;
        }
        long long totalColSum = 0;
        for(int i=0;i<m;i++){
            totalColSum += col[i];
        }
        long long leftColSum = 0;
        for(int i=0;i<m-1;i++){
            leftColSum += col[i];
            totalColSum -= col[i];
            if(leftColSum == totalColSum){
                return true;
            }
        }
        long long totalRowSum = 0;
        for(int i=0;i<n;i++){
            totalRowSum += row[i];
        }
        long long leftRowSum = 0;
        for(int i=0;i<n-1;i++){
            leftRowSum += row[i];
            totalRowSum -= row[i];
            if(leftRowSum == totalRowSum){
                return true;
            }
        }
        return false;
    }
};