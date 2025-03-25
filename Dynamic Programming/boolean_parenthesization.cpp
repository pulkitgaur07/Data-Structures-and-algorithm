// Question : You are given a boolean expression s containing
// 'T' ---> true
// 'F' ---> false 
// and following operators between symbols
// &   ---> boolean AND
// |   ---> boolean OR
// ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer is guaranteed to fit within a 32-bit integer.

// Examples:

// Input: s = "T|T&F^T"
// Output: 4
// Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

// Input: s = "T^F|F"
// Output: 2
// Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).

// Constraints:
// 1 ≤ |s| ≤ 100 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Recursion

class Solution {
public:
int dfs(int i, int j, bool isT, string &s){
        if(i>j) return 0;
        else if(i==j){
            if(isT) return s[i]=='T';
            else return s[i]=='F';
        }
        int ways=0;
        for(int ind=i+1; ind<=j-1; ind+=2){
            int lT=dfs(i, ind-1, 1, s);
            int lF=dfs(i, ind-1, 0, s);
            int rT=dfs(ind+1, j, 1, s);
            int rF=dfs(ind+1, j, 0, s);
            if(isT){
                if(s[ind]=='&'){
                    ways+=(lT*rT);
                }
                else if(s[ind]=='|'){
                    ways+=((lT*rT)+(lT*rF)+(lF*rT));
                }
                else{
                    ways+=((lT*rF)+(lF*rT));
                }
            }
            else{
                if(s[ind]=='&'){
                    ways+=((lF*rF)+(lT*rF)+(lF*rT));
                }
                else if(s[ind]=='|'){
                    ways+=(lF*rF);
                }
                else{
                    ways+=((lT*rT)+(lF*rF));
                }
            }
        }
        return ways;
    }
    
    int countWays(string &s) {
        int n=s.length();
        return dfs(0, n-1, 1, s);
    }
};

// Using Memoization

class Solution {
public:
int dfs(int i, int j, bool isT, string &s, vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        else if(i==j){
            if(isT) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isT]!=-1) return dp[i][j][isT];
        int ways=0;
        for(int ind=i+1; ind<=j-1; ind+=2){
            int lT=dfs(i, ind-1, 1, s, dp);
            int lF=dfs(i, ind-1, 0, s, dp);
            int rT=dfs(ind+1, j, 1, s, dp);
            int rF=dfs(ind+1, j, 0, s, dp);
            if(isT){
                if(s[ind]=='&'){
                    ways+=(lT*rT);
                }
                else if(s[ind]=='|'){
                    ways+=((lT*rT)+(lT*rF)+(lF*rT));
                }
                else{
                    ways+=((lT*rF)+(lF*rT));
                }
            }
            else{
                if(s[ind]=='&'){
                    ways+=((lF*rF)+(lT*rF)+(lF*rT));
                }
                else if(s[ind]=='|'){
                    ways+=(lF*rF);
                }
                else{
                    ways+=((lT*rT)+(lF*rF));
                }
            }
        }
        return dp[i][j][isT]=ways;
    }
    
    int countWays(string &s) {
        int n=s.length();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return dfs(0, n-1, 1, s, dp);
    }
};