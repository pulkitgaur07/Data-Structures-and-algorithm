// Question : Given an integer n. You need to generate all the binary strings of n characters representing bits.

// Note: Return the strings in  ascending order.

// Examples:

// Input: n = 2
// Output: [00, 01, 10, 11]
// Explanation: As each position can be either 0 or 1, the total possible combinations are 4.
// Input: n = 3
// Output: [000, 001, 010, 011, 100, 101, 110, 111]
// Explanation: As each position can be either 0 or 1, the total possible combinations are 8.
// Constraints:
// 1 ≤ n ≤ 20

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int i,int n,string val,vector<string>&ans){
        if(i == n){
            ans.push_back(val);
            return;
        }
        dfs(i+1,n,val+'0',ans);
        dfs(i+1,n,val+'1',ans);
    }
    vector<string> binstr(int n) {
        vector<string>ans;
        dfs(0,n,"",ans);
        return ans;
    }
};