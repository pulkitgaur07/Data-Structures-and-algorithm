// Question : We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation:
// The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 2
// Explanation:
// The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

// Example 3:
// Input: nums = [1,1,1,1]
// Output: 0
// Explanation:
// No harmonic subsequence exists.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -109 <= nums[i] <= 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0, j = 0;
        int ans = 0;
        while(j<n){
            if((nums[j]-nums[i]) < 1){
                j++;
            }
            else if((nums[j]-nums[i]) == 1){
                ans = max(ans,(j-i+1));
                j++;
            }
            else{
                while((nums[j]-nums[i]) > 1){
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};