// Question : Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0

// Constraints:

// 0 <= n <= 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10][2][10];
    int solve(int ind, int tight, int count, string &s){
        if(ind==(s.size())) return count;
        if(dp[ind][tight][count]!=-1) return dp[ind][tight][count];
        int ub = tight?(s[ind]-'0'):9;
        int ans=0;
        for(int i=0;i<=ub;i++){
            ans+=solve(ind+1,tight&(i==ub),count+(i==1),s);
        }
        return dp[ind][tight][count]=ans;
    }
    
public:
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        int ans = solve(0,1,0,s);
        return ans;
    }
};