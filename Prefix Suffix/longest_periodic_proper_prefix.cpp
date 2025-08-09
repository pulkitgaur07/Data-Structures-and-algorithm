// Question : Given a string s, find the length of longest periodic proper prefix of s. If no such prefix exists, return -1.
// A periodic proper prefix is a non empty prefix of s (but not the whole string), such that repeating this prefix enough times produces a string that starts with s.

// Examples:

// Input: s = "aaaaaa"
// Output: 5
// Explanation: Repeating the proper prefix "aaaaa" forms "aaaaaaaaaa...", which contains "aaaaa" as a prefix. No longer proper prefix satisfies this.
// Input: s = "abcab"
// Output: 3
// Explanation: Repeating the proper prefix "abc" forms "abcabc., which contains "abcab" as a prefix. No longer proper prefix satisfies this.
// Input: s = "ababd"
// Output: -1
// Explanation: No proper prefix satisfying the given condition.
// Constraints:
// 1 ≤ s.size() ≤ 105
// s consists of lowercase English alphabets

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n = s.length();
        int i=0;
        int j=n-1;
        int pos = n-1;
        int ans = 0;
        while(j<n && pos>0){
            if(s[i] == s[j]){
                i++;
                j++;
                ans++;
            }
            else{
                i=0;
                pos--;
                j=pos;
                ans = 0;
            }
        }
        if(pos==0) return -1;
        return n-ans;
    }
};