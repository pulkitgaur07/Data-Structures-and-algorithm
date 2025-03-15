// Question : You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

// Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.

// Examples:

// Input: coins[] = [25, 10, 5], sum = 30
// Output: 2
// Explanation: Minimum 2 coins needed, 25 and 5  

// Input: coins[] = [9, 6, 5, 1], sum = 19
// Output: 3
// Explanation: 19 = 9 + 9 + 1

// Input: coins[] = [5, 1], sum = 0
// Output: 0
// Explanation: For 0 sum, we do not need a coin

// Input: coins[] = [4, 6, 2], sum = 5
// Output: -1
// Explanation: Not possible to make the given sum.

// Constraints:
// 1 ≤ sum * coins.size() ≤ 106
// 0 <= sum <= 104
// 1 <= coins[i] <= 104
// 1 <= coins.size() <= 103

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int i,vector<int> &coins,int sum){
        if(i == 0){
            if(sum % coins[0] == 0) return sum/coins[0];
            else return 1e8;
        }
        int notTake = dfs(i-1,coins,sum);
        int take = INT_MAX;
        if(coins[i] <= sum){
            take = 1+dfs(i,coins,sum-coins[i]);
        }
        return min(notTake,take);
    }
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        int ans = dfs(n-1,coins,sum);
        return ans == 1e8 ? -1 : ans;
    }
};


// Using Memoization

class Solution {
public:
    int dfs(int i,vector<int> &coins,int sum,vector<vector<int>> &dp){
        if(i == 0){
            if(sum % coins[0] == 0) return sum/coins[0];
            else return 1e8;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int notTake = dfs(i-1,coins,sum,dp);
        int take = INT_MAX;
        if(coins[i] <= sum){
            take = 1+dfs(i,coins,sum-coins[i],dp);
        }
        return dp[i][sum] = min(notTake,take);
    }
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans = dfs(n-1,coins,sum,dp);
        return ans == 1e8 ? -1 : ans;
    }
};

// Using Tabulation

class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,1e8));
        for(int target=0;target<=sum;target++){
            if(target%coins[0] == 0){
                dp[0][target] = target/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){
                int notTake = dp[i-1][target];
                int take = INT_MAX;
                if(coins[i] <= target){
                    take = 1+dp[i][target-coins[i]];
                }
                dp[i][target] = min(notTake,take);
            }
        }
        int ans = dp[n-1][sum];
        return ans == 1e8 ? -1 : ans;
    }
};

// Using Space Optimization

class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<int>curr(sum+1,1e8),prev(sum+1,1e8);
        for(int target=0;target<=sum;target++){
            if(target%coins[0] == 0){
                prev[target] = target/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){
                int notTake = prev[target];
                int take = INT_MAX;
                if(coins[i] <= target){
                    take = 1+curr[target-coins[i]];
                }
                curr[target] = min(notTake,take);
            }
            prev = curr;
        }
        int ans = prev[sum];
        return ans == 1e8 ? -1 : ans;
    }
};