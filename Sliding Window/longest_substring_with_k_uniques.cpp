// Question : You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

// Note : If no such substring exists, return -1. 

// Examples:

// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.
// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
// Constraints:
// 1 ≤ s.size() ≤ 105
// 1 ≤ k ≤ 26

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        vector<int>freq(26,0);
        int i=0, j=0;
        int ans=-1, diff=0;
        while(j<n){
            if(!freq[s[j]-'a']) diff++;
            freq[s[j]-'a']++;
            if(diff < k){
                j++;
            }
            else if(diff == k){
                ans = max(ans,(j-i+1));
                j++;
            }
            else{
                while(diff > k && i<n){
                    freq[s[i]-'a']--;
                    if(!freq[s[i]-'a']){
                        diff--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};