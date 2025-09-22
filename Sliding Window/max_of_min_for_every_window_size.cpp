// Question : You are given an integer array arr[], the task is to find the maximum of minimum values for every window size k where 1≤ k ≤ arr.size().

// For each window size k, consider all contiguous subarrays of length k, determine the minimum element in each subarray, and then take the maximum among all these minimums.

// Return the results as an array, where the element at index i represents the answer for window size i+1.

// Examples :

// Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
// Output: [70, 30, 20, 10, 10, 10, 10] 
// Explanation: 
// Window size 1: minimums are [10, 20, 30, 50, 10, 70, 30], maximum of minimums is 70.
// Window size 2: minimums are [10, 20, 30, 10, 10, 30], maximum of minimums is 30.
// Window size 3: minimums are [10, 20, 10, 10, 10], maximum of minimums is 20.
// Window size 4–7: minimums are [10, 10, 10, 10], maximum of minimums is 10.
// Input: arr[] = [10, 20, 30]
// Output: [30, 20, 10]
// Explanation: 
// Window size 1: minimums of  [10], [20], [30], maximum of minimums is 30.
// Window size 2: minimums of [10, 20], [20,30], maximum of minimums is 20.
// Window size 3: minimums of [10,20,30], maximum of minimums is 10.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 106

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        for (int i = 0; i < n; ++i) {
            int window_size = right[i] - left[i] - 1;
            result[window_size - 1] = max(result[window_size - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            result[i] = max(result[i], result[i + 1]);
        }
        return result;
    }
};

