// Question : Given a string s in Roman number format, your task is to convert it to an integer. Various symbols and their values are given below.
// Note: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

// Examples:

// Input: s = "IX"
// Output: 9
// Explanation: IX is a Roman symbol which represents 10 – 1 = 9.
// Input: s = "XL"
// Output: 40
// Explanation: XL is a Roman symbol which represents 50 – 10 = 40.
// Input: s = "MCMIV"
// Output: 1904
// Explanation: M is 1000, CM is 1000 – 100 = 900, and IV is 4. So we have total as 1000 + 900 + 4 = 1904.
// Constraints:
// 1 ≤ roman number ≤ 3999
// s[i] belongs to [I, V, X, L, C, D, M]

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToDecimal(string &s) {
        int n = s.size()-1;
        unordered_map<char,int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum=0;
        for(int i=0;i<n;i++){
            if(mpp[s[i]] < mpp[s[i+1]]){
                sum-=mpp[s[i]];
            }
            else{
                sum+=mpp[s[i]];
            }
        }
        sum+=mpp[s[n]];
        return sum;
    }
};