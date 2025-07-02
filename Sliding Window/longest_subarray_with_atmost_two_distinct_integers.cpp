// Question : Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.

// Examples:

// Input: arr[] = [2, 1, 2]
// Output: 3
// Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
// Input: arr[] = [3, 1, 2, 2, 2, 2]
// Output: 5
// Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        vector<int>freq(100001,0);
        int i = 0, j = 0;
        int diff = 0, ans = 0;
        while(j<n){
            if(!freq[arr[j]]) diff++;
            freq[arr[j]]++;
            if(diff <= 2){
                ans = max(ans,(j-i+1));
                j++;
            }
            else{
                while(diff > 2 && i<n){
                    freq[arr[i]]--;
                    if(!freq[arr[i]]){
                        diff--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};