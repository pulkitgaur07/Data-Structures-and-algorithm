// Question : Given a number n. The task is to generate all binary numbers with decimal values from 1 to n.

// Examples:

// Input: n = 4
// Output: ["1", "10", "11", "100"]
// Explanation: Binary numbers from 1 to 4 are 1, 10, 11 and 100.
// Input: n = 6
// Output: ["1", "10", "11", "100", "101", "110"]
// Explanation: Binary numbers from 1 to 6 are 1, 10, 11, 100, 101 and 110.
// Constraints:
// 1 ≤ n ≤ 106

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            string binary = "";
            int num = i;
            while (num > 0) {
                binary = char('0' + (num % 2)) + binary;
                num /= 2;
            }
            result.push_back(binary);
        }
        return result;
    }
};