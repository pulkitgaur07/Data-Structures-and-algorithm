// Question : You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

// Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +"). 
// And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
// It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

// Examples:

// Input: arr[] = ["2", "3", "1", "*", "+", "9", "-"]
// Output: -4
// Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
// Input: arr[] = ["2", "3", "^", "1", "+"]
// Output: 9
// Explanation: If the expression is converted into an infix expression, it will be 2 ^ 3 + 1 = 8 + 1 = 9.
// Constraints:
// 3 ≤ arr.size() ≤ 103
// arr[i] is either an operator: "+", "-", "*", "/" or "^", or an integer in the range [-104, 104]

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isOperator(const string &s) {
        return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
    }

    long long applyOp(long long a, long long b, const string &op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            long long res = a / b;
            if ((a ^ b) < 0 && a % b != 0) res--;
            return res;
        }
        if (op == "^") return pow(a, b);
        return 0;
    }
    
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        for (string &s : arr) {
            if (isOperator(s)) {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = applyOp(a, b, s);
                st.push(res);
            } else {
                st.push(stoll(s));
            }
        }
        return (int)st.top();
    }
};