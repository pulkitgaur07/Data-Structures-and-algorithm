// Question : You are given an array arr[] of integers, where each element represents the number of coins in a pile. You are also given an integer k.
// Your task is to remove the minimum number of coins such that the absolute difference between the number of coins in any two updated piles is at most k.

// Note: You can also remove a pile by removing all the coins of that pile.

// Examples:

// Input: arr[] = [2, 2, 2, 2], k = 0
// Output: 0
// Explanation: For any two piles the difference in the number of coins is <= 0. So no need to remove any coin. 
// Input: arr[] = [1, 5, 1, 2, 5, 1], k = 3
// Output: 2
// Explanation: If we remove one coin each from both the piles containing 5 coins, then for any two piles the absolute difference in the number of coins is <= 3. 
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104
// 0 ≤ k ≤ 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n,0);
        sort(arr.begin(), arr.end());
        partial_sum(arr.begin(), arr.end(),prefix.begin());
        int ans = INT_MAX;
        int prev = 0;
        for(int i = 0;i<n;i++){
            int index = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            if(i>0 && (arr[i] != arr[i-1])){
                prev = prefix[i-1];
            }
            int x = prev + (prefix[n-1] - prefix[index-1]) - (n-index) *(arr[i] + k);
            ans = min(ans, x);
        }
        return ans;
    }
};