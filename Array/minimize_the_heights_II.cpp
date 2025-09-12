// Question : Given an array arr[] denoting heights of n towers and a positive integer k.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by k
// Decrease the height of the tower by k
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by k for each tower. After the operation, the resultant array should not contain any negative integers.

// Examples :

// Input: k = 2, arr[] = [1, 5, 8, 10]
// Output: 5
// Explanation: The array can be modified as [1+k, 5-k, 8-k, 10-k] = [3, 3, 6, 8]. The difference between the largest and the smallest is 8-3 = 5.
// Input: k = 3, arr[] = [3, 9, 12, 16, 20]
// Output: 11
// Explanation: The array can be modified as [3+k, 9+k, 12-k, 16-k, 20-k] = [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17-6 = 11. 
// Constraints
// 1 ≤ k ≤ 107
// 1 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 107

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;
        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
        for (int i = 0; i < n-1; i++) {
            int minH = min(smallest, arr[i+1] - k);
            int maxH = max(largest, arr[i] + k);
            if (minH < 0) continue;
            ans = min(ans, maxH - minH);
        }
        return ans;
    }
};