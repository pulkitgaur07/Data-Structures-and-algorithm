// Question : You are given a string s consisting only of the characters '(' and ')'. Your task is to determine the minimum number of parentheses (either '(' or ')') that must be inserted at any positions to make the string s a valid parentheses string.

// A parentheses string is considered valid if:

// Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
// Every closing parenthesis ')' has a corresponding opening parenthesis '('.
// Parentheses are properly nested.
// Examples:

// Input: s = "(()("
// Output: 2
// Explanation: There are two unmatched '(' at the end, so we need to add two ')' to make the string valid.
// Input: s = ")))"
// Output: 3
// Explanation: Three '(' need to be added at the start to make the string valid.
// Input: s = ")()()"
// Output: 1 
// Explanation: The very first ')' is unmatched, so we need to add one '(' at the beginning.
// Constraints:
// 1 ≤ s.size() ≤ 105
// s[i] ∈ { '(' , ')' }

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0;
        int close = 0;
        for(char cha : s){
            if(cha=='('){
                open++;
            } else if(cha ==')'){
                if(open>0){
                    open--;
                } else{
                    close++;
                }
            }
        }
        return open+close;
    }
};