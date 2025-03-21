// Question : Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
// Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
// Determine the maximum amount he can loot.

// Examples:

// Input: arr[] = [6, 5, 5, 7, 4]
// Output: 15
// Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6 + 5 + 4 = 15.

// Input: arr[] = [1, 5, 3]
// Output: 5
// Explanation: Loot only 2nd house and get maximum amount of 5.

// Input: arr[] = [4, 4, 4, 4]
// Output: 8
// Explanation: The optimal choice is to loot every alternate house. Looting the 1st and 3rd houses, or the 2nd and 4th, both give a maximum total of 4 + 4 = 8.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int i,vector<int>&arr){
        if(i == -1) return 0;
        if(i == 0) return arr[0];
        int notTake = dfs(i-1,arr);
        int take = arr[i]+dfs(i-2,arr);
        return max(notTake,take);
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        return dfs(n-1,arr);
    }
};

// Using Memoization

class Solution {
public:
    int dfs(int i,vector<int>&arr,vector<int> &dp){
        if(i == 0) return 0;
        if(i == 1) return arr[0];
        if(dp[i] != -1) return dp[i];
        int notTake = dfs(i-1,arr,dp);
        int take = arr[i]+dfs(i-2,arr,dp);
        return dp[i] = max(notTake,take);
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return dfs(n,arr,dp);
    }
};

// Using Tabulation

class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        dp[0] = 0; dp[1] = arr[0];
        for(int i=2;i<=n;i++){
            int notTake = dp[i-1];
            int take = arr[i-1]+dp[i-2];
            dp[i] = max(notTake,take);
        }
        return dp[n];
    }
};

// Using Space Optimization

class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int secondPrev = 0, prev = arr[0];
        for(int i=2;i<=n;i++){
            int curr = 0;
            int notTake = prev;
            int take = arr[i-1]+secondPrev;
            curr = max(notTake,take);
            secondPrev = prev;
            prev = curr;
        }
        return prev;
    }
};