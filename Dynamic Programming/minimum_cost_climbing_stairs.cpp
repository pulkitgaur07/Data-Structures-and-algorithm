// Question : Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
// Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.

// Examples:

// Input: cost[] = [10, 15, 20]
// Output: 15
// Explanation: Cheapest option is to start at cost[1], pay that cost, and go to the top.



// Input: cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// Output: 6
// Explanation: Cheapest option is to start on cost[0], and only step on 1s, skipping cost[3].


// Constraints:
// 2 ≤ cost.size() ≤ 105
// 0 ≤ cost[i] ≤ 999

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int i,int n,vector<int> &cost){
        if(i>=n){
            return 0;
        }
        int oneStep = cost[i]+dfs(i+1,n,cost);
        int twoStep = cost[i]+dfs(i+2,n,cost);
        return min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return dfs(-1,n,cost);
    }
};

// Using Memoization

class Solution {
public:
    int dfs(int i,int n,vector<int> &cost,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i+1] != -1) return dp[i+1];
        int oneStep = cost[i]+dfs(i+1,n,cost,dp);
        int twoStep = cost[i]+dfs(i+2,n,cost,dp);
        return dp[i+1] = min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+3,-1);
        return dfs(-1,n,cost,dp);
    }
};