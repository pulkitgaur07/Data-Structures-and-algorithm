// Question : You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

// Key Details:

// The valid operators are '+', '-', '*', and '/'.
// Each operand is guaranteed to be a valid integer or another expression.
// The division operation between two integers always rounds the result towards zero, discarding any fractional part.
// No division by zero will occur in the input.
// The input is a valid arithmetic expression in Reverse Polish Notation.
// The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int evaluate(vector<string>& arr) {
          int n = arr.size();
          stack<int>st;
          for(int i=0;i<n;i++){
              if(arr[i] == "+" || arr[i] == "-" || arr[i] == "/" || arr[i] == "*"){
                  int b = st.top();
                  st.pop();
                  int a = st.top();
                  st.pop();
                  char opr = arr[i][0];
                  int val;
                  if(opr == '+') val = a+b;
                  else if(opr == '-') val = a-b;
                  else if(opr == '/') val = a/b;
                  else val = a*b;
                  st.push(val);
              }
              else{
                  st.push(stoi(arr[i]));
              }
          }
          return st.top();
      }
  };