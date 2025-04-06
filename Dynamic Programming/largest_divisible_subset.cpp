// Question : Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Example 2:
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int i,int prev,vector<int>&ans,vector<int> &nums){
        if(i==nums.size()){
            return 0;
        }
        int notTake = solve(i+1,prev,ans,nums);
        int take = 0;
        if(prev==-1 || nums[i]%nums[prev]==0){
            take = 1+solve(i+1,i,ans,nums);
        }
        return max(notTake,take);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(lastIndex!=hash[lastIndex]){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};