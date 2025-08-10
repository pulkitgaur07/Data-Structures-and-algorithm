// Question : Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.

// Note: A substring is palindromic if it reads the same forwards and backwards.

// Examples:

// Input: s = "abaab"
// Output: 3
// Explanation: All palindromic substrings (of length > 1) are: "aba", "aa", "baab".
// Input: s = "aaa"
// Output: 3
// Explanation: All palindromic substrings (of length > 1) are: "aa", "aa", "aaa".
// Input: s = "abbaeae"
// Output: 4
// Explanation: All palindromic substrings (of length > 1) are: "bb", "abba", "aea", "eae".
// Constraints:
// 2 ≤ s.size() ≤ 5 * 103
// s contains only lowercase english characters

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPS(string &s) {
        int ct = 0;
        for(int i=0;i<s.size();i++){
            for(int j=1;i-j>=0 && i+j < s.size(); j++){
                if(s[i-j]!=s[i+j]) break;
                ct++;
            }
            for(int j=1;i-j+1>=0 && i+j < s.size(); j++){
                if(s[i-j+1]!=s[i+j]) break;
                ct++;
            }
        }
        return ct;
    }
};