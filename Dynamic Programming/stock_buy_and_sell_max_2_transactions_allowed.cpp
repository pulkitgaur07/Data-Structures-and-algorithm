// Question : In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

// You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).

// Examples:

// Input: prices[] = [10, 22, 5, 75, 65, 80]
// Output: 87
// Explanation: 
// Trader will buy at 10 and sells at 22. 
// Profit earned in 1st transaction = 22 - 10 = 12. 
// Then he buys at 5 and sell at 80. 
// Profit earned in 2nd transaction = 80 - 5 = 75. 
// Total profit earned = 12 + 75 = 87. 

// Input: prices[] = [2, 30, 15, 10, 8, 25, 80]
// Output: 100
// Explanation: 
// Trader will buy at 2 and sells at 30. 
// Profit earned in 1st transaction = 30 - 2 = 28. 
// Then he buys at 8 and sell at 80. 
// Profit earned in 2nd transaction = 80 - 8 = 72. 
// Total profit earned = 28 + 72 = 100.

// Constraints:
// 1 <= prices.size() <= 105
// 1 <= prices[i] <= 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int i,vector<int> &prices,int k,bool canBuy){
        if(k==0) return 0;
        if(i>=prices.size())return 0;
        int profit=0;
        if(canBuy){
            int buyIt=dfs(i+1,prices,k,0)-prices[i];
            int doNotBuyIt=dfs(i+1,prices,k,1);
            profit=max(buyIt,doNotBuyIt);
            
        }else{
            int sellit=dfs(i+1,prices,k-1,1)+prices[i];
            int doNotSellit=dfs(i+1,prices,k,0);
            profit=max(sellit,doNotSellit);
        }
        return profit;
    }
    int maxProfit(vector<int> &prices) {
        return dfs(0,prices,2,1);
    }
};

// Using Memoization

class Solution {
public:
    int dfs(int i,vector<int> &prices,int k,bool canBuy,vector<vector<vector<int>>>&dp){
        if(k==0) return 0;
        if(i>=prices.size())return 0;
        if(dp[i][k][canBuy]!=-1) return dp[i][k][canBuy];
        int profit=0;
        if(canBuy){
            int buyIt=dfs(i+1,prices,k,0,dp)-prices[i];
            int doNotBuyIt=dfs(i+1,prices,k,1,dp);
            profit=max(buyIt,doNotBuyIt);
            
        }else{
            int sellit=dfs(i+1,prices,k-1,1,dp)+prices[i];
            int doNotSellit=dfs(i+1,prices,k,0,dp);
            profit=max(sellit,doNotSellit);
        }
        return dp[i][k][canBuy]=profit;
    }
    int maxProfit(vector<int> &prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return dfs(0,prices,2,1,dp);
    }
};