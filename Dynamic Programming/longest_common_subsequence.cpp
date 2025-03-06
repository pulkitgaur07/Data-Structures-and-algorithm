// Question : Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

// A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

// Examples:

// Input: s1 = "ABCDGH", s2 = "AEDFHR"
// Output: 3
// Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.

// Input: s1 = "ABC", s2 = "AC"
// Output: 2
// Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.

// Input: s1 = "XYZW", s2 = "XYWZ"
// Output: 3
// Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.

// Constraints:
// 1<= s1.size(), s2.size() <=103
// Both strings s1 and s2 contain only uppercase English letters.

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using Recursion
    int dfs(int i, int j, int n, int m, string &s1, string &s2){
        if (i == n || j == m){
            return 0;
        }
        if (s1[i] == s2[j]){
            return 1 + dfs(i + 1, j + 1, n, m, s1, s2);
        }
        return max(dfs(i + 1, j, n, m, s1, s2), dfs(i, j + 1, n, m, s1, s2));
    }
    int lcs(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        int ans = dfs(0, 0, n, m, s1, s2);
        return ans;
    }
};

class Solution {
public:
    // Using Memoization
    int dfs(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if (i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + dfs(i + 1, j + 1, n, m, s1, s2, dp);
        }
        return dp[i][j] = max(dfs(i + 1, j, n, m, s1, s2, dp), dfs(i, j + 1, n, m, s1, s2, dp));
    }
    int lcs(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = dfs(0, 0, n, m, s1, s2, dp);
        return ans;
    }
};

class Solution {
public:
    // Using Tabulation
    int lcs(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int ans = dp[0][0];
        return ans;
    }
};