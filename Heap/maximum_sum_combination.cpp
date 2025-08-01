// Question : You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

// Examples:

// Input: a[] = [3, 2], b[] = [1, 4], k = 2
// Output: [7, 6]
// Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
// Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
// Output: [10, 9, 9]
// Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
// Constraints:
// 1 ≤ a.size() = b.size() ≤ 105
// 1 ≤ k ≤ a.size()
// 1 ≤ a[i], b[i] ≤ 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<int> ans(k);
        pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
        unordered_map<long long, int> mp;
        for(int u = 0; u < k; u++) {
            auto it = pq.top(); pq.pop();
            int i = it.second.first, j = it.second.second;
            if(mp.count(i * 1e9 + j) != 0) {
                u--;
                continue;
            }
            mp[i * 1e9 + j] = 1;
            ans[u] = it.first;
            if(i - 1 >= 0) pq.push({a[i - 1] + b[j], {i - 1, j}});
            if(j - 1 >= 0) pq.push({a[i] + b[j - 1], {i, j - 1}});
        }
        return ans;
    }
};