// Question : You are given a 2D integer array intervals[][] of length n, where each intervals[i] = [start, end] represents a closed interval (i.e., all integers from start to end, inclusive). You are also given an integer k. An integer is called Powerful if it appears in at least k intervals. Find the maximum Powerful Integer.

// Note: If no integer occurs at least k times return -1.

// Examples:

// Input : n = 3, intervals[][] = [[1, 3], [4, 6], [3, 4]], k = 2
// Output: 4
// Explanation: Integers 3 and 4 appear in 2 intervals. The maximum is 4.
// Input : n = 4, intervals[][] = [[1, 4], [12, 45], [3, 8], [10, 12]], k = 3
// Output: -1
// Explanation: No integer appears in at least 3 intervals.
// Input : n = 5, intervals[][] = [[16, 21], [5, 8], [12, 17], [17, 29], [9, 24]], k = 3
// Output: 21
// Explanation: Integers 16, 17, 18, 19, 20 and 21 appear in at least 3 intervals. The maximum is 21.
// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ intervals[i][0] ≤ intervals[i][1] ≤ 109
// 1 ≤ k ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        int n = intervals.size();
        map<int,int>mp;
        for(auto it : intervals){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int cnt = 0 , ans = -1;
        for(auto &x : mp){
            if(cnt >= k){
                ans = max(ans , x.first-1);
            }
            cnt += x.second;
        }
        return ans;
    }
};