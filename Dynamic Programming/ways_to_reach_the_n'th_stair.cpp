// Question : There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

// Examples:

// Input: n = 1
// Output: 1
// Explanation: There is only one way to climb 1 stair. 

// Input: n = 2
// Output: 2
// Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}. 

// Input: n = 4
// Output: 5
// Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.

// Constraints:
// 1 ≤ n ≤ 44

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int n){
        if(n == 0){
            return 1;
        }
        int ans = 0;
        ans += dfs(n-1);
        if(n > 1){
            ans += dfs(n-2);
        }
        return ans;
    }
    int countWays(int n) {
        return dfs(n);
    }
};


// Using Memoization

class Solution {
public:
    int dfs(int n,vector<int> &dp){
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        ans += dfs(n-1,dp);
        if(n > 1){
            ans += dfs(n-2,dp);
        }
        return dp[n] = ans;
    }
    int countWays(int n) {
        vector<int>dp(n+1,-1);
        return dfs(n,dp);
    }
};

// Using Tabulation

class Solution {
public:
    int countWays(int n) {
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++){
            int ans = 0;
            ans += dp[i-1];
            if(i > 1){
                ans += dp[i-2];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

// Using Space Optimization

class Solution {
public:
    int countWays(int n) {
        int prev = 1, secondPrev = -1, cur = 1;
        for(int i=1;i<=n;i++){
            int ans = 0;
            ans += prev;
            if(i > 1){
                ans += secondPrev;
            }
            cur = ans;
            secondPrev = prev;
            prev = cur;
        }
        return prev;
    }
};