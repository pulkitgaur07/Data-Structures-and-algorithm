// Question : Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
// If multiple such subarrays exist, return the one that starts at the smallest index.

// Examples:

// Input: arr[] = [8, 4, 5, 6, 7], x = 3 
// Output: [4, 5, 6, 7] 
// Explanation: The sub-array described by index [1..4], i.e. [4, 5, 6, 7]
// contains no two elements whose absolute differnce is greater than 3.
// Input: arr[] = [1, 10, 12, 13, 14], x = 2 
// Output: [12, 13, 14] 
// Explanation: The sub-array described by index [2..4], i.e. [12, 13, 14]
// contains no two elements whose absolute differnece is greater than 2. 
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 109
// 0 ≤ x ≤ 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> maxDq, minDq;
        int left = 0, bestStart = 0, bestLen = 0;
        for (int right = 0; right < n; right++) {
            while (!maxDq.empty() && arr[maxDq.back()] < arr[right]) 
                maxDq.pop_back();
            maxDq.push_back(right);
            while (!minDq.empty() && arr[minDq.back()] > arr[right]) 
                minDq.pop_back();
            minDq.push_back(right);
            while (arr[maxDq.front()] - arr[minDq.front()] > x) {
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();
                left++;
            }
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
        }
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};