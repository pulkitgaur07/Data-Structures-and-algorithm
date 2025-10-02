// Question : Given two integers n and k, the task is to find all valid combinations of k numbers that adds up to n based on the following conditions:

// Only numbers from the range [1, 9] used.
// Each number can only be used at most once.
// Note: You can return the combinations in any order, the driver code will print them in sorted order.

// Examples:

// Input: n = 9, k = 3
// Output: [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
// Explanation: There are three valid combinations of 3 numbers that sum to 9: [1 ,2, 6], [1, 3, 5] and [2, 3, 4].
// Input: n = 3, k = 3
// Output: []
// Explanation: It is not possible to pick 3 distinct numbers from 1 to 9 that sum to 3, so no valid combinations exist.
// Constraints:
// 1 ≤ n ≤ 50
// 1 ≤ k ≤ 9

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int i, int n, int k, vector<int> v, vector<vector<int>>& ans){
        if(n == 0 && k == 0){
            ans.push_back(v);  
            return;
        }
        if(n <= 0 || k <= 0) return;
        
        for(int j = i; j <= 9; j++){
            v.push_back(j);
            solve(j + 1, n - j, k - 1, v, ans);  
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1, n, k, v, ans);
        return ans;
    }
};