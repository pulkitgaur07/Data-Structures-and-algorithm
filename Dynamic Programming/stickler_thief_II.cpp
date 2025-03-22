// Question : You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
// Determine the maximum amount the thief can steal.

// Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

// Examples:

// Input: arr[] = [2, 3, 2]
// Output: 3
// Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.

// Input: arr[] = [1, 2, 3, 1]
// Output: 4
// Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4

// Input: arr[] = [2, 2, 3, 1, 2]
// Output: 5
// Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5

// Constraints:
// 2 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
    int dfs(int i,vector<int> &arr,vector<int> &dp){
        if(i == -1) return 0;
        if(i == 0) return arr[0];
        if(dp[i] != -1) return dp[i];
        int notTake = dfs(i-1,arr,dp);
        int take = arr[i]+dfs(i-2,arr,dp);
        return dp[i] = max(notTake,take);
    }
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i != 0) arr1.push_back(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(i != (n-1)) arr2.push_back(arr[i]);
        }
        vector<int>dp1(n-1,-1),dp2(n-1,-1);
        int ans1 = dfs(n-2,arr1,dp1);
        int ans2 = dfs(n-2,arr2,dp2);
        return max(ans1,ans2);
    }
};

// Using Memoization

class Solution {
public:
    int dfs(int i,vector<int> &arr,vector<int> &dp){
        if(i == 0) return arr[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int notTake = dfs(i-1,arr,dp);
        int take = arr[i]+dfs(i-2,arr,dp);
        return dp[i] = max(notTake,take);
    }
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i != 0) arr1.push_back(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(i != (n-1)) arr2.push_back(arr[i]);
        }
        vector<int>dp1(n-1,-1),dp2(n-1,-1);
        int ans1 = dfs(n-2,arr1,dp1);
        int ans2 = dfs(n-2,arr2,dp2);
        return max(ans1,ans2);
    }
};

// Using Tabulation

class Solution {
public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i != 0) arr1.push_back(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(i != (n-1)) arr2.push_back(arr[i]);
        }
        vector<int>dp1(n-1,0),dp2(n-1,0);
        dp1[0] = arr1[0]; dp2[0] = arr2[0];
        for(int i=1;i<n-1;i++){
            int notTake = dp1[i-1];
            int take = arr1[i];
            if(i > 1) take += dp1[i-2];
            dp1[i] = max(notTake,take);
        }
        for(int i=1;i<n-1;i++){
            int notTake = dp2[i-1];
            int take = arr2[i];
            if(i > 1) take += +dp2[i-2];
            dp2[i] = max(notTake,take);
        }
        int ans1 = dp1[n-2];
        int ans2 = dp2[n-2];
        return max(ans1,ans2);
    }
};

// Using Space Optimization

class Solution {
public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i != 0) arr1.push_back(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(i != (n-1)) arr2.push_back(arr[i]);
        }
        vector<int>dp1(n-1,0),dp2(n-1,0);
        int prev1 = arr1[0], secondPrev1 = 0; int prev2 = arr2[0], secondPrev2 = 0;
        for(int i=1;i<n-1;i++){
            int curr1 = 0;
            int notTake = prev1;
            int take = arr1[i];
            if(i > 1) take += secondPrev1;
            curr1 = max(notTake,take);
            secondPrev1 = prev1;
            prev1 = curr1;
        }
        for(int i=1;i<n-1;i++){
            int curr2 = 0;
            int notTake = prev2;
            int take = arr2[i];
            if(i > 1) take += secondPrev2;
            curr2 = max(notTake,take);
            secondPrev2 = prev2;
            prev2 = curr2;
        }
        int ans1 = prev1;
        int ans2 = prev2;
        return max(ans1,ans2);
    }
};