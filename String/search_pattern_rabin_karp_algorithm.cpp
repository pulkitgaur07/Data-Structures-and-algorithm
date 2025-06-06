// Question : Given two strings:

// A text string in which you want to search.

// A pattern string that you are looking for within the text.

// Return all positions (1-based indexing) where the pattern occurs as a substring in the text. If the pattern does not occur, return an empty list.

// All characters in both strings are lowercase English letters (a to z).

// Examples:

// Input: text = "birthdayboy", pattern = "birth"
// Output: [1]
// Explanation: The string "birth" occurs at index 1 in text.
// Input: text = "geeksforgeeks", pattern = "geek"
// Output: [1, 9]
// Explanation: The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.
// Constraints:
// 1<= text.size() <=5*105
// 1<= pattern.size() <= text.size()

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        int n = pat.length() ;
        int m = txt.length() ;
        vector<int>lps(n , 0) ;
        int len = 0 ; 
        for(int i = 1 ; i < n ; i ++){
            while(len > 0 && pat[len] != pat[i]) len = lps[len - 1] ;
            if(pat[len] == pat[i]) len ++ ;
            lps[i] = len ;
        }
        vector<int>ans ;
        int j = 0 ;
        for(int i = 0 ; i < m ; i ++){
            while(j > 0 && pat[j] != txt[i]) j = lps[j - 1] ;
            if(txt[i] == pat[j]) j ++ ;
            if(j == n){
                ans.push_back(i - n + 2) ;
                j = lps[n - 1] ;
            } 
        }
        return ans ;
    }
};