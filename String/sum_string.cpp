// Question : Given a string s consisting of digits, determine whether it can be classified as a sum-string.

// A sum-string is a string that can be split into more than two non-empty substrings such that:


// The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

// This condition must apply recursively to the substrings before it.

// The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

// Examples:

// Input: s = "12243660"
// Output: true
// Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
// 36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
// Input: s = "1111112223"
// Output: true
// Explanation: Split the string as {"1", "111", "112", "223"}, where:
// 112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
// Input: s = "123456"
// Output: false
// Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
// Constraints:
// 1 ≤ s.size() ≤ 100
// String consists of characters from '0' to '9'.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s_add(string a, string b) {
        string ans = "";
        int d = 0,i=a.size()-1,j =b.size()-1;
        while (i >= 0 || j >= 0 || d) {
            int c= d;
            if(i>=0) c+=a[i--]-'0';
            if(j>=0) c+=b[j--]-'0';
            ans.push_back(c % 10+'0');
            d=c/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool isValid(string s,int start,string a,string b) {
        while (start<s.size()) {
            string c=s_add(a, b);
            int len =c.length();
            if(start+len >s.size() || s.substr(start,len)!= c)
                return false;
            start+= len;
            a=b;
            b=c;
        }
        return true;
    }
    bool isSumString(string &s) {
        int n=s.length();
        for(int i =1; i<n; i++) {
            for (int j =1;i + j< n;j++) {
                string a=s.substr(0, i);
                string b=s.substr(i, j);
                if((a.length()> 1&& a[0]=='0') || 
                    (b.length()> 1&& b[0]=='0')) {
                    continue;
                }

                if(isValid(s,i+j,a,b))
                    return true;
            }
        }
        return false;
    }
};