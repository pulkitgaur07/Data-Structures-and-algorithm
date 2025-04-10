// Question : You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum.
// Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

// Note that digit_sum(x) denotes the sum of the digits of x.

// Example 1:

// Input: num1 = "1", num2 = "12", min_sum = 1, max_sum = 8
// Output: 11
// Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.
// Example 2:

// Input: num1 = "1", num2 = "5", min_sum = 1, max_sum = 5
// Output: 5
// Explanation: The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we return 5.

// Constraints:

// 1 <= num1 <= num2 <= 1022
// 1 <= min_sum <= max_sum <= 400

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[24][2][210];
    int mod = (int)1e9+7;
    
    int solve(int ind, int tight, int sum, string nums, int min_sum, int max_sum){
        if(ind==(nums.size())){
            return ((sum>=min_sum) && (sum<=max_sum));
        }
        if(dp[ind][tight][sum]!=-1) return dp[ind][tight][sum];
        int ub = tight?(nums[ind]-'0'):9;
        int ans = 0;
        for(int i=0;i<=ub;i++){
            ans+=solve(ind+1,tight&(i==ub),sum+i,nums,min_sum,max_sum);
            ans%=mod;
        }
        return dp[ind][tight][sum]=ans;
    }
    
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n = num1.size();
        if((num1[n-1]-'0')>0){
            char ch = char(num1[n-1]-'0'-1+48);
            num1[n-1] = ch;
        }
        else{
            char ch = char(num1[n-2]-'0'-1+48);
            num1[n-2] = ch;
            num1[n-1] = '9';
        }
        memset(dp,-1,sizeof(dp));
        int ans1 = solve(0,1,0,num1,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
        int ans2 = solve(0,1,0,num2,min_sum,max_sum);
        int ans = ans2-ans1;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        return ans;
    }
};