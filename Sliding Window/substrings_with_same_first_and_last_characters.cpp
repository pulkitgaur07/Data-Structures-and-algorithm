// Question : Given a string s consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

// Examples:

// Input: s = "abcab"
// Output: 7
// Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"
// Input: s = "aba"
// Output: 4
// Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"
// Constraints:
// 1 <= |s| <= 104
// s contains lower case english alphabets

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute force Approach

class Solution {
public:
    int countSubstring(string &s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(s[i] == s[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Optimized Approach

class Solution {
public:
    int countSubstring(string &s) {
        int n = s.size();
        vector<int>freq(26,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            ans += freq[s[i]-'a'];
        }
        return ans;
    }
};