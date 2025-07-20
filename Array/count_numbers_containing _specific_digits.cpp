// Question : You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive integers can be formed such that at least one digit from the array arr[] appears in the number.

// Examples:

// Input: n = 1, arr[] = [1, 2, 3]
// Output: 3
// Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
// Input: n = 2, arr[] = [3, 5]
// Output: 34
// Explanation: There are a total of 34  two digit numbers which contain atleast  one out of  [3, 5].
// Constraints:
//   1 ≤ n ≤ 9
//   1 ≤ arr.size() ≤ 10
//   0 ≤ arr[i] ≤ 9

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        int totalNum = 1;
        for(int i = 1; i <= n; i++){
            if(i == 1){
                totalNum = totalNum * 9;
            } else {
                totalNum = totalNum * 10;
            }
        }
        int digits = arr.size();
        int not_containing = 1;
        for(int i = 1; i <= n; i++){
            if(i ==1){
                if(arr[0] == 0){
                    not_containing = not_containing * (9 - digits + 1);
                }else {
                    not_containing = not_containing * (10 - digits - 1);
                }
            } else {
                not_containing = not_containing * (10 - digits);
            }
        }
        return totalNum - not_containing;
    }
};