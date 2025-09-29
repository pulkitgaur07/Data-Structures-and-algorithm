// Question : You are given an array arr[] of integers and two integers a and b, You have to find the maximum possible sum of a contiguous subarray whose length is at least a and at most b.

// Examples:

// Input: arr[] = [4, 5, -1, -2, 6], a = 2, b = 4
// Output: 9
// Explanation: The subarray [4, 5] has length 2 and sum 9, which is the maximum among all subarrays of length between 2 and 4.
// Input: arr[] = [-1, 3, -1, -2, 5, 3, -5, 2, 2], a = 3, b = 5
// Output: 8
// Explanation: The subarray [3, -1, -2, 5, 3] has length 5 and sum 8, which is the maximum among all subarrays of length between 3 and 5.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -105 ≤ arr[i] ≤ 105
// 1 ≤ a ≤ b ≤ arr.size()

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        int ans = INT_MIN;
        deque <int> q;
        vector <int> pre(n+1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + arr[i-1];
        for(int i = a; i <= n; i++){
            while(!q.empty() && q.front() + b < i) q.pop_front();
            while(!q.empty() && pre[q.back()] > pre[i-a]) q.pop_back();
            q.push_back(i-a);
            
            ans = max(ans, pre[i] - pre[q.front()]);
        }
        return ans;
    }
};