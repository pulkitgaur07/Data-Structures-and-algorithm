// Question : Given a string s, return the length of the longest palindromic subsequence.

// A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

// A palindromic sequence is a sequence that reads the same forward and backward.

// Examples:

// Input: s = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.

// Input: s = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.

// Input: s = "agbdba"
// Output: 5
// Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.

// Constraints:
// 1 ≤ s.size() ≤ 1000
// The string contains only lowercase letters.

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using Recursion
    int dfs(int i, int j, string &s) {
        if (i > j)
            return 0;
        if (i == j){
            return 1;
        }
        if (s[i] == s[j]){
            return 2 + dfs(i + 1, j - 1, s);
        }
        return max(dfs(i + 1, j, s), dfs(i, j - 1, s));
    }
    int longestPalinSubseq(string &s){
        int n = s.size();
        int ans = dfs(0, n - 1, s);
        return ans;
    }
};

class Solution {
public:
    // Using Memoization
    int dfs(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (i == j){
            return 1;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]){
            return dp[i][j] = 2 + dfs(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = max(dfs(i + 1, j, s, dp), dfs(i, j - 1, s, dp));
    }
    int longestPalinSubseq(string &s){
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = dfs(0, n - 1, s, dp);
        return ans;
    }
};