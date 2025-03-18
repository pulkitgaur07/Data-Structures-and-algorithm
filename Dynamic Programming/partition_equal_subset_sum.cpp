// Question : Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

// Note: Each element must be in exactly one subset.

// Examples:

// Input: arr = [1, 5, 11, 5]
// Output: true
// Explanation: The two parts are [1, 5, 5] and [11].

// Input: arr = [1, 3, 5]
// Output: false
// Explanation: This array can never be partitioned into two such parts.

// Constraints:
// 1 ≤ arr.size ≤ 100
// 1 ≤ arr[i] ≤ 200

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    bool dfs(int i,vector<int> &arr, int sum){
        if(sum == 0) return true;
        if(i == 0){
            return arr[0] == sum;
        }
        int notTake = dfs(i-1,arr,sum);
        int take = false;
        if(arr[i] <= sum){
            take = dfs(i-1,arr,sum-arr[i]);
        }
        return notTake | take;
    }
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0 ;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum&1) return false;
        sum /= 2;
        return dfs(n-1,arr,sum);
    }
};

// Using Memoization

class Solution {
public:
    bool dfs(int i,vector<int> &arr, int sum,vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(i == 0){
            return arr[0] == sum;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int notTake = dfs(i-1,arr,sum,dp);
        int take = false;
        if(arr[i] <= sum){
            take = dfs(i-1,arr,sum-arr[i],dp);
        }
        return dp[i][sum] = notTake | take;
    }
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0 ;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum&1) return false;
        sum /= 2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return dfs(n-1,arr,sum,dp);
    }
};

// Using Tabulation

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0 ;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum&1) return false;
        sum /= 2;
        vector<vector<int>>dp(n,vector<int>(sum+1,false));
        for(int i=0;i<n;i++) dp[i][0] = true;
        for(int tar=0;tar<=sum;tar++) dp[0][tar] = arr[0]==tar;
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=sum;tar++){
                int notTake = dp[i-1][tar];
                int take = false;
                if(arr[i] <= tar){
                    take = dp[i-1][tar-arr[i]];
                }
                dp[i][tar] = notTake | take;
            }
        }
        return dp[n-1][sum];
    }
};

// Using Space Optimization

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0 ;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum&1) return false;
        sum /= 2;
        vector<int>prev(sum+1,false),curr(sum+1,false);
        for(int i=0;i<n;i++) prev[0] = true;
        for(int tar=0;tar<=sum;tar++) prev[tar] = arr[0]==tar;
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=sum;tar++){
                int notTake = prev[tar];
                int take = false;
                if(arr[i] <= tar){
                    take = prev[tar-arr[i]];
                }
                curr[tar] = notTake | take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};