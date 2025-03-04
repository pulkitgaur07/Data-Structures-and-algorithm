// Question : Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

// A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

// Examples:

// Input: arr[] = [5, 8, 3, 7, 9, 1]
// Output: 3
// Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.

// Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
// Output: 6
// Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.

// Input: arr[] = [3, 10, 2, 1, 20]
// Output: 3
// Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.

// Constraints:
// 1 ≤ arr.size() ≤ 103
// 0 ≤ arr[i] ≤ 106

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Using Recursion
    int dfs(int prev_ind, int ind, vector<int> &arr, int n){
        if (ind == n){
            return 0;
        }
        int notTake = dfs(prev_ind, ind + 1, arr, n);
        int take = 0;
        if (prev_ind == -1 || arr[ind] > arr[prev_ind]){
            take = 1 + dfs(ind, ind + 1, arr, n);
        }
        return max(notTake, take);
    }
    int lis(vector<int> &arr){
        int n = arr.size();
        int ans = dfs(-1, 0, arr, n);
        return ans;
    }
};

class Solution{
public:
    // Using Memoization
    int dfs(int prev_ind, int ind, vector<int> &arr, int n, vector<vector<int>> &dp){
        if (ind == n){
            return 0;
        }
        if (dp[prev_ind + 1][ind] != -1)
            return dp[prev_ind + 1][ind];
        int notTake = dfs(prev_ind, ind + 1, arr, n, dp);
        int take = 0;
        if (prev_ind == -1 || arr[ind] > arr[prev_ind]){
            take = 1 + dfs(ind, ind + 1, arr, n, dp);
        }
        return dp[prev_ind + 1][ind] = max(notTake, take);
    }
    int lis(vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = dfs(-1, 0, arr, n, dp);
        return ans;
    }
};

class Solution{
    public:
        // Using Tabulation
        int lis(vector<int> &arr){
            int n = arr.size();
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
            for(int prev_ind=n-1;prev_ind>=-1;prev_ind--){
                for(int ind=n-1;ind>=0;ind--){
                    int notTake = dp[prev_ind+1][ind+1];
                    int take = 0;
                    if(prev_ind == -1 || arr[ind]>arr[prev_ind]){
                        take = 1+dp[ind+1][ind+1];
                    }
                    dp[prev_ind+1][ind] = max(notTake,take);
                }
            }
            int ans = dp[-1+1][0];
            return ans;
        }
    };
