// Question : Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.

// Examples:

// Input : s = "2911285"
// Output : true
// Explanation: 2911285 / 13 = 223945, which is a whole number with no remainder.
// Input : s = "27"
// Output : false
// Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).
// Constraints:
// 1 ≤  s.size()  ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool divby13(string &s) {
        int n = s.size();
        int mod = 0;
        for(int i=0;i<n;i++){
            mod = (mod*10 + (s[i]-'0'))%13;
        }
        if(mod == 0) return true;
        return false;
    }
};