// Question : Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion + Memoization

class Solution {
public:
    int dfs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if (i == 0 || j == 0){
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i - 1] == s2[j - 1]){
            return dp[i][j] = 1 + dfs(i - 1, j - 1, s1, s2, dp);
        }
        else{
            return dp[i][j] = max(dfs(i - 1, j, s1, s2, dp), dfs(i, j - 1, s1, s2, dp));
        }
    }
    string shortestCommonSupersequence(string str1, string str2){
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int a = dfs(n, m, str1, str2, dp);
        int i = n, j = m;
        string str = "";
        for (int i = 0; i < (m + n - a); i++){
            str += '$';
        }
        int ind = m + n - a - 1;
        while (i > 0 && j > 0){
            if (str1[i - 1] == str2[j - 1]){
                str[ind] = str1[i - 1];
                i--;
                j--;
                ind--;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1]){
                str[ind] = str1[i - 1];
                i--;
                ind--;
            }
            else{
                str[ind] = str2[j - 1];
                j--;
                ind--;
            }
        }
        while (i > 0){
            str[ind] = str1[i - 1];
            i--;
            ind--;
        }
        while (j > 0){
            str[ind] = str2[j - 1];
            j--;
            ind--;
        }
        return str;
    }
};

// Using Tabulation

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string str(m + n - dp[n][m], '$');
        int ind = str.size() - 1;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                str[ind--] = str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                str[ind--] = str1[i - 1];
                i--;
            }
            else
            {
                str[ind--] = str2[j - 1];
                j--;
            }
        }
        while (i > 0)
        {
            str[ind--] = str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            str[ind--] = str2[j - 1];
            j--;
        }
        return str;
    }
};