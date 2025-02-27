// Question : Given q queries, You task is to implement the following four functions for a stack:

// push(x) – Insert an integer x onto the stack.
// pop() – Remove the top element from the stack.
// peek() - Return the top element from the stack. If the stack is empty, return -1.
// getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
// Each query can be one of the following:

// 1 x : Push x onto the stack.
// 2 : Pop the top element from the stack.
// 3 : Return the top element from the stack. If the stack is empty, return -1.
// 4 : Return the minimum element from the stack.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      stack<int>st;
      stack<int>minStack;
      
      Solution() {
          //code here
      }
  
      // Add an element to the top of Stack
      void push(int x) {
          st.push(x);
          if(minStack.empty() || x<=minStack.top()){
              minStack.push(x);
          }
      }
  
      // Remove the top element from the Stack
      void pop() {
          if(!minStack.empty() && minStack.top() == st.top()){
              minStack.pop();
          }
          if(!st.empty()){
              st.pop();
          }
      }
  
      // Returns top element of the Stack
      int peek() {
          if(st.empty()){
              return -1;
          }
          return st.top();
      }
  
      // Finds minimum element of Stack
      int getMin() {
          if(minStack.empty()){
              return -1;
          }
          return minStack.top();
      }
  };