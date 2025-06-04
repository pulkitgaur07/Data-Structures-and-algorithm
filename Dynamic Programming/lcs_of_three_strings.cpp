// Question : Given three strings s1, s2, and s3 containing uppercase letters, lowercase letters, and digits, find the length of longest common sub-sequence in all three given strings.

// Examples:

// Input: s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common subsequence with length 5.
// Input: s1 = "abcd1e2", s2 = "bc12ea", s3 = "bd1ea"
// Output: 3
// Explanation:  Longest common subsequence is "b1e" i.e. length = 3.
// Constraints:
// 1  ≤  s1.size(), s2.size(), s3.size()  ≤  100

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Solve(string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp,int i,int j,int k){
        if(i>=s1.length() || j>=s2.length() || k>=s3.length()){
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(s1[i]==s2[j] && s2[j]==s3[k]){
            ans=1+Solve(s1,s2,s3,dp,i+1,j+1,k+1);
        }
        else{
            ans=max({Solve(s1,s2,s3,dp,i+1,j,k),Solve(s1,s2,s3,dp,i,j+1,k),Solve(s1,s2,s3,dp,i,j,k+1)});
        }
        return dp[i][j][k]=ans;
    }
    
    int lcsOf3(string& s1, string& s2, string& s3) {
        vector<vector<vector<int>>>dp(s1.length(),vector<vector<int>>(s2.length(),vector<int>(s3.length(),-1)));
        return Solve(s1,s2,s3,dp,0,0,0);
    }
};