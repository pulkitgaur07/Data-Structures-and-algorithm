// Question : Given a string s, find all possible ways to partition it such that every substring in the partition is a palindrome.

// Examples:

// Input: s = "geeks"
// Output: [[g, e, e, k, s], [g, ee, k, s]]
// Explanation: [g, e, e, k, s] and [g, ee, k, s] are the only partitions of "geeks" where each substring is a palindrome.
// Input: s = "abcba"
// Output: [[a, b, c, b, a], [a, bcb, a], [abcba]]
// Explanation: [a, b, c, b, a], [a, bcb, a] and [abcba] are the only partitions of "abcba" where each substring is a palindrome.
// Constraints:
// 1 ≤ s.size() ≤ 20

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPal(int l, int r, string &s, vector<vector<int>>&dp){
        if(l>=r) return true;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]=isPal(l+1, r-1, s, dp);
        }else return dp[l][r]=0;
    }
  
    void solve(int ind, int n, string &s, vector<string>&tmp, 
    vector<vector<string>>&ans, vector<vector<int>>&dp){
        if(ind>=n){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(isPal(ind, i, s, dp)){
                tmp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, n, s, tmp, ans, dp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        int n=s.length();
        vector<string>tmp;
        vector<vector<string>>ans;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        solve(0, n, s, tmp, ans, dp);
        return ans;
    }
};