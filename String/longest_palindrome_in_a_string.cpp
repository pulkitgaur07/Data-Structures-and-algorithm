// Question : Given a string s, your task is to find the longest palindromic substring within s.

// A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

// A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

// Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

// Examples :

// Input: s = “forgeeksskeegfor”
// Output: “geeksskeeg”
// Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.

// Input: s = “Geeks”
// Output: “ee”
// Explanation: "ee" is the longest palindromic substring of "Geeks".

// Input: s = “abc”
// Output: “a”
// Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.

// Constraints:
// 1 ≤ s.size() ≤ 103
// s consist of only lowercase English letters.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while (i <= j){
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string &s) {
        int n = s.size();
        int x = 0, y = 0;
        int len = 1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    if((j-i+1)>len){
                        len = j-i+1;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        string ans = "";
        while(x <= y){
            ans += s[x];
            x++;
        }
        return ans;
    }
};