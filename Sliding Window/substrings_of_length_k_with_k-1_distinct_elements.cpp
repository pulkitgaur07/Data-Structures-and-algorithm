// Question : Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.

// Examples:

// Input: s = "abcc", k = 2
// Output: 1
// Explaination: Possible substring of length k = 2 are,
// ab : 2 distinct characters
// bc : 2 distinct characters
// cc : 1 distinct characters
// Only one valid substring so, count is equal to 1.
// Input: "aabab", k = 3
// Output: 3
// Explaination: Possible substring of length k = 3 are, 
// aab : 2 distinct charcters
// aba : 2 distinct characters
// bab : 2 distinct characters
// All these substring are valid so, the total count is equal to 3.
// Constrains:
// 1 ≤ s.size() ≤ 105
// 2 ≤ k ≤ 27

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.size();
        vector<int>freq(26,0);
        int i=0, j=0;
        int diff = 0;
        int ans = 0;
        while(j<n){
            if(!freq[s[j]-'a']) diff++;
            freq[s[j]-'a']++;
            if((j-i+1) < k){
                j++;
            }
            else{
                if(diff == (k-1)){
                    ans++;
                }
                freq[s[i]-'a']--;
                if(!freq[s[i]-'a']){
                    diff--;
                }
                i++; j++;
            }
        }
        return ans;
    }
};