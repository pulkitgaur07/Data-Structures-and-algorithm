// Question : Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) 
// for a total value of 80.

// Constraints:
// 2 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int i,vector<int> &val, vector<int> &wt, int W){
        if(i==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        int notTake = dfs(i-1,val,wt,W);
        int take = 0;
        if(wt[i]<=W){
            take = val[i]+dfs(i-1,val,wt,W-wt[i]);
        }
        return max(notTake,take);
    }
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        return dfs(n-1,val,wt,W);
    }
};

// Using Memoization

class Solution {
public:
    int dfs(int i,vector<int> &val, vector<int> &wt, int W,vector<vector<int>> &dp){
        if(i==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[i][W] != -1) return dp[i][W];
        int notTake = dfs(i-1,val,wt,W,dp);
        int take = 0;
        if(wt[i]<=W){
            take = val[i]+dfs(i-1,val,wt,W-wt[i],dp);
        }
        return dp[i][W] = max(notTake,take);
    }
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return dfs(n-1,val,wt,W,dp);
    }
};

// Using Tabulation

class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int weight=0;weight<=W;weight++){
            if(wt[0]<=weight){
                dp[0][weight] = val[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int weight=0;weight<=W;weight++){
                int notTake = dp[i-1][weight];
                int take = 0;
                if(wt[i]<=weight){
                    take = val[i]+dp[i-1][weight-wt[i]];
                }
                dp[i][weight] = max(notTake,take);
            }
        }
        return dp[n-1][W];
    }
};