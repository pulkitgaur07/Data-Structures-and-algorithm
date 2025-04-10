// Question : Given two positive integers low and high represented as strings, find the count of stepping numbers in the inclusive range [low, high].

// A stepping number is an integer such that all of its adjacent digits have an absolute difference of exactly 1.

// Return an integer denoting the count of stepping numbers in the inclusive range [low, high].

// Since the answer may be very large, return it modulo 109 + 7.

// Note: A stepping number should not have a leading zero.

// Example 1:

// Input: low = "1", high = "11"
// Output: 10
// Explanation: The stepping numbers in the range [1,11] are 1, 2, 3, 4, 5, 6, 7, 8, 9 and 10. There are a total of 10 stepping numbers in the range. Hence, the output is 10.
// Example 2:

// Input: low = "90", high = "101"
// Output: 2
// Explanation: The stepping numbers in the range [90,101] are 98 and 101. There are a total of 2 stepping numbers in the range. Hence, the output is 2. 

// Constraints:

// 1 <= int(low) <= int(high) < 10100
// 1 <= low.length, high.length <= 100
// low and high consist of only digits.
// low and high don't have any leading zeros.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = (int)1e9+7;
    int dp[101][2][2][10];
    
    int solve(int ind, int tight,int leading, int prev, string &s){
        if(ind==(s.size())) return 1;
        if(dp[ind][tight][leading][prev]!=-1) return dp[ind][tight][leading][prev];
        int end = tight?(s[ind]-'0'):9;
        int ans=0;
        if(leading){
            for(int i=0;i<=end;i++){
                ans += solve(ind+1,tight&(i==end),leading&(i==0),i,s);
                ans %=mod;
            }
        }
        else{
            int first = prev-1;
            int last = prev+1;
            if(first>=0 && first<=end){
                ans += solve(ind+1,tight&(first==end),0,first,s);
                ans %=mod;
            }
            if(last>=0 && last<=end){
                ans += solve(ind+1,tight&(last==end),0,last,s);
                ans %=mod;
            }
        }
        return dp[ind][tight][leading][prev]=ans;
    }
    
    
    int countSteppingNumbers(string low, string high) {
        int n = low.size();
        if((low[n-1]-'0')>0){
            low[n-1] = char(low[n-1]-'0'-1+48);
        }
        else{
            low[n-2] = char(low[n-2]-'0'-1+48);
            low[n-1] = '9';
        }
        memset(dp,-1,sizeof(dp));
        int ans1 = solve(0,1,1,0,low);
        memset(dp,-1,sizeof(dp));
        int ans2 = solve(0,1,1,0,high);
        int ans = ans2-ans1;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        return ans;
    }
};