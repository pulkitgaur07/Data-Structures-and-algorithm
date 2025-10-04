// Question : Given a string s that contains only digits (0-9) and an integer target, return all possible strings by inserting the binary operator ' + ', ' - ', and/or ' * ' between the digits of s such that the resultant expression evaluates to the target value.

// Note:

// Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine.
// It is allowed to not insert any of the operators.
// Driver code will print the final list of strings in lexicographically smallest order.
// Examples:

// Input: s = "124", target = 9
// Output: ["1+2*4"]
// Explanation: The valid expression that evaluate to 9 is 1 + 2 * 4
// Input: s = "125", target = 7
// Output: ["1*2+5", "12-5"]
// Explanation: The two valid expressions that evaluate to 7 are 1 * 2 + 5 and 12 - 5.
// Input: s = "12", target = 12
// Output: ["12"] 
// Explanation: s itself matches the target. No other expressions are possible.
// Input: s = "987612", target = 200
// Output: []
// Explanation: There are no expressions that can be created from "987612" to evaluate to 200.
// Constraints:
// 1 ≤ s.size() ≤ 9
// s consists of only digits (0-9).
// -231 ≤ target ≤ 231-1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> ans;
    void solve(string &num, int target, int idx, long long currVal, long long prevNum, string expr) {
        int n = num.size();
        if (idx == n) {
            if (currVal == target) ans.push_back(expr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i != idx && num[idx] == '0') break;
            string part = num.substr(idx, i - idx + 1);
            long long val = stoll(part);
            if (idx == 0) {
                solve(num, target, i + 1, val, val, part);
            } 
            else {
                solve(num, target, i + 1, currVal + val, val, expr + "+" + part);
                solve(num, target, i + 1, currVal - val, -val, expr + "-" + part);
                solve(num, target, i + 1, currVal - prevNum + prevNum * val, prevNum * val, expr + "*" + part);
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        ans.clear();
        solve(s, target, 0, 0, 0, "");
        return ans;
    }
};