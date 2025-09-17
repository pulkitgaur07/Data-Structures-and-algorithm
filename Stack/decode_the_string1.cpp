// Question : Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times. k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets. Return the final decoded string.

// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:

// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// Inner substring “2[ca]” breakdown into “caca”.
// Now, new string becomes “3[bcaca]”
// Similarly “3[bcaca]” becomes “bcacabcacabcaca” which is final result.
// Input: s = "3[ab]"
// Output: "ababab"
// Explanation: The substring "ab" is repeated 3 times giving "ababab".
// Constraints:
// 1 ≤ |s| ≤ 105 
// 1 ≤ k ≤ 100

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decodedString(string &s) {
        stack<string>num;
        string res="";
        int c=0;
        for(char ch:s )
        {
            if(ch==']')
            {
                string str="";
                while(num.top()!="[")
                {
                   str=num.top()+str;
                   num.pop();
                }
                num.pop();
                res="";
                res=str+res;
                str=res;
                string dig="";
                while(!num.empty() && isdigit(num.top()[0]))
                {
                    dig=num.top()+dig;
                    num.pop();
                }
                long long n= stoll(dig);
                while(--n > 0)
                {
                     res+=str;
                }
                
                num.push(res);
            }else
            {
                num.push(string()+ch);
            }
        }
        num.pop();
        while(!num.empty())
        {
            res=num.top()+res;
            num.pop();
        }
        return res;
    }
};