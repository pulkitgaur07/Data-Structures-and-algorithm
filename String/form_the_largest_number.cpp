// Question : Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

// Examples:

// Input: arr[] = [3, 30, 34, 5, 9]
// Output: 9534330
// Explanation: Given numbers are [3, 30, 34, 5, 9], the arrangement [9, 5, 34, 3, 30] gives the largest value.
// Input: arr[] = [54, 546, 548, 60]
// Output: 6054854654
// Explanation: Given numbers are [54, 546, 548, 60], the arrangement [60, 548, 546, 54] gives the largest value.
// Input: arr[] = [3, 4, 6, 5, 9]
// Output: 96543
// Explanation: Given numbers are [3, 4, 6, 5, 9], the arrangement [9, 6, 5, 4, 3] gives the largest value.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class cmp {
  public:
    bool operator()(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }
};

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        int n = arr.size();
        vector<string> v(n);
        string num = "";
        int dig;
        char digit;
        int x;
        for(int i = 0; i < n; i++) {
            x = arr[i];
            num = "";
            while(x) {
                dig = x % 10;
                digit = dig + '0';
                num = digit + num;
                x /= 10;
            }
            if(num == "") v[i] = "0";
            else v[i] = num;
        }
        sort(v.begin(), v.end(), cmp());
        string ans = "";
        int f = 1; 
        for(string &s: v) {
            if(s != "0") f = 0;
            ans += s;
        }
        if(f) return "0";
        return ans;
    }
};