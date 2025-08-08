// Question : Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
// Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

// Examples :

// Input: s = "abab"
// Output: 2
// Explanation: The string "ab" is the longest prefix and suffix. 
// Input: s = "aabcdaabc"
// Output: 4
// Explanation: The string "aabc" is the longest prefix and suffix.
// Input: s = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest prefix and suffix. 
// Constraints:
// 1 ≤ s.size() ≤ 106
// s contains only lowercase English alphabets.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        int maxi =0;
        vector<int>idx;
        for(int i=n-2;i>=0;i--){
            if (s[i]==s[n-1]){
                string k = s.substr(0,i+1);
                string m = s.substr(n-i-1,i+1);
                if (k==m){
                    return i+1;
                }  
            }
        } 
        return 0;
    }
};