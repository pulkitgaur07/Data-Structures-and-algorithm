// Question : Given an encoded string s, the task is to decode it. The encoding rule is :

// k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:

// Input: s = "1[b]"
// Output: "b"
// Explanation: "b" is present only one time.

// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// 1. Inner substring “2[ca]” breakdown into “caca”.
// 2. Now, new string becomes “3[bcaca]”
// 3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.

// Constraints:
// 1 ≤ |s| ≤ 105

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      string decodedString(string &s) {
          int n = s.size();
          stack<string> st;
          int num = 0;
          int i = n-1;
          while(i>=0){
              if(s[i]>='0' && s[i]<='9'){
                  string t;
                  while(i>=0 && s[i]>='0' && s[i]<='9'){
                      t.push_back(s[i]);
                      i--;
                  }
                  reverse(t.begin(),t.end());
                  num = stoi(t);
                  string p="";
                  st.pop();
                  while(st.top()!="]"){
                      p+=st.top();
                      st.pop();
                  }
                  st.pop();
                  string pp="";
                  for(int i=0;i<num;i++){
                      pp = pp + p;
                  }
                  st.push(pp);
              }
              else{
                  string t;
                  t.push_back(s[i]);
                  st.push(t);
                  i--;
              }
          }
          string ans = "";
          while(!st.empty()){
              ans+=st.top();
              st.pop();
          }
          return ans;
      }
  };