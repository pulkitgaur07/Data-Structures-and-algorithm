// Question : Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.

// Examples:

// Input: s = "768"
// Output: "867"
// Explanation: Swapping the 1st and 3rd characters(7 and 8 respectively), gives the lexicographically largest string.
// Input: s = "333"
// Output: "333"
// Explanation: Performing any swaps gives the same result i.e "333".
// Constraints:
// 1 ≤ |s| ≤ 105
// '0' ≤ s[i] ≤ '9'

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string largestSwap(string &s) {
        string res=s;
        sort(res.rbegin(), res.rend());
        int i=0;
        while(i<s.length() && s[i]==res[i]) i++;
        if(i==s.length()) return s;
        int j=s.length()-1;
        while(j>i && s[j]!=res[i]) j--;
        swap(s[i], s[j]);
        return s;
    }
};