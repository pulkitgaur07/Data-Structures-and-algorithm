// Question : Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
// Constraints:
// 1 <= arr.size() <= 200
// 1<= arr[i] <= 200
// 1<= sum <= 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    bool dfs(int i,vector<int> &arr, int sum){
        if(sum == 0) return true;
        if(i==0){
            return arr[0]==sum;
        }
        int notTake = dfs(i-1,arr,sum);
        int take = false;
        if(arr[i] <= sum){
            take = dfs(i-1,arr,sum-arr[i]);
        }
        return notTake|take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return dfs(n-1,arr,sum);
    }
};

// Using Memoization

class Solution {
public:
    bool dfs(int i,vector<int> &arr, int sum,vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(i==0){
            return arr[0]==sum;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int notTake = dfs(i-1,arr,sum,dp);
        int take = false;
        if(arr[i] <= sum){
            take = dfs(i-1,arr,sum-arr[i],dp);
        }
        return dp[i][sum] = notTake|take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return dfs(n-1,arr,sum,dp);
    }
};