// Question : Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

// Examples:

// Input: arr[] = [10, 2, -2, -20, 10], k = -10
// Output: 3
// Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
// Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
// Output: 2
// Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
// Input: arr[] = [1, 3, 5], k = 0
// Output: 0
// Explaination: No subarray with 0 sum.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -103 ≤ arr[i] ≤ 103
// -105 ≤ k ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        map<int,int>mp;
        mp[0] = 1;
        int ans = 0,sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            int val = sum-k;
            if(mp.find(val) != mp.end()){
                ans += mp[val];
            }
            mp[sum]++;
        }
        return ans;
    }
};