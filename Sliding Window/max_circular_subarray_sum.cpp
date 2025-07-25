// Question : You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
// Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
// Output: 23
// Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
// Input: arr[] = [5, -2, 3, 4]
// Output: 12
// Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -104 ≤ arr[i] ≤ 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int maxEnding = arr[0];     
        for (int i = 1; i < arr.size(); i++) {
            maxEnding = max(arr[i], maxEnding + arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
    
    int minSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int minEnding = arr[0];     
        for (int i = 1; i < arr.size(); i++) {
            minEnding = min(arr[i], minEnding + arr[i]);
            res = min(res, minEnding);
        }
        return res;
    }
    
    int maxCircularSum(vector<int> &arr) {
        int ans1 = maxSubarraySum(arr);
        int ans2 = minSubarraySum(arr);
        int total = 0;
        for(auto it : arr) total += it;
        if(total == ans2) return ans1;
        int ans = max(ans1,total-ans2);
        return ans;
    }
};