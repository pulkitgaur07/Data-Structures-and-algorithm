// Question : Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).

// Examples:

// Input: arr[] = [4, 6, 1, 2, 3, 8]
// Output: 10
// Explanation: The elements which are not in LIS is 4 and 6.
// Input: arr[] = [5, 4, 3, 2, 1]
// Output: 14
// Explanation: The elements which are not in LIS is 5, 4, 3 and 2.
// Constraints:
// 1 ≤ arr.size() ≤ 103
// 1 ≤ arr[i] ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> prev(n, -1);
        vector<int> lis;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i],[&](int idx, int val) { return arr[idx] < val; });
            int pos = it - lis.begin();
            if (pos == lis.size()) {
                lis.push_back(i);
            } else {
                lis[pos] = i;
            }
            if (pos != 0)
                prev[i] = lis[pos - 1];
        }
        int lisSum = 0;
        int i = lis.back();
        while (i != -1) {
            lisSum += arr[i];
            i = prev[i];
        }
        return totalSum - lisSum;
    }
};