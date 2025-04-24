// Question : Given an array of integers arr[] where, every element appears thrice except for one which occurs once.
// Find that element which occurs once.

// Examples:

// Input: arr[] = [1, 10, 1, 1]
// Output: 10
// Explanation: 10 occurs once in the array while the other element 1 occurs thrice.
// Input: arr[] = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]
// Output: 3
// Explanation: All elements except 3 occurs thrice in the array.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// arr.size() % 3 = 1
// -109 ≤ arr[i] ≤ 109

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSingle(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<32;i++){
            int val = 0;
            for(int j=0;j<n;j++){
                val += abs(arr[j])&(1<<i);
                val = val%3;
            }
            if(val) ans += (1<<i);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ans==arr[i]) cnt++;
        }
        if(cnt==1) return ans;
        return -ans;
    }
};