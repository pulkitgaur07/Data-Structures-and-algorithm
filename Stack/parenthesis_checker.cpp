// Question : Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.

// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
      bool isBalanced(string& s) {
          int n = s.size();
          stack<char>st;
          for(int i=0;i<n;i++){
              if(!st.empty() && ((st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']') || (st.top() == '(' && s[i] == ')'))){
                  st.pop();
              }
              else{
                  st.push(s[i]);
              }
          }
          return st.size() ? 0 : 1;
      }
  };