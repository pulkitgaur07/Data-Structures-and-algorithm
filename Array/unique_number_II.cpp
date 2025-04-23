// Question : Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

// Examples:

// Input: arr[] = [1, 2, 3, 2, 1, 4]
// Output: [3, 4] 
// Explanation: 3 and 4 occur exactly once.
// Input: arr[] = [2, 1, 3, 2]
// Output: [1, 3]
// Explanation: 1 and 3 occur exactly once.
// Input: arr[] = [2, 1, 3, 3]
// Output: [1, 2]
// Explanation: 1 and 2 occur exactly once.
// Constraints:
// 2 ≤ arr.size() ≤ 106 
// 1 ≤ arr[i] ≤ 5 * 106
// arr.size() is even

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNum(vector<int>& arr) {
        int n = arr.size();
        int xr = 0;
        for(int i=0;i<n;i++){
            xr ^= arr[i];
        }
        int pos = 0;
        for(int i=0;i<32;i++){
            if(xr & (1<<i)){
                pos = i;
                break;
            }
        }
        int lxr = xr, rxr = xr;
        for(int i=0;i<n;i++){
            if((1<<pos)&arr[i]){
                lxr ^= arr[i];
            }
            else{
                rxr ^= arr[i];
            }
        }
        vector<int>ans;
        if(lxr < rxr){
            ans.push_back(lxr);
            ans.push_back(rxr);
        }
        else{
            ans.push_back(rxr);
            ans.push_back(lxr);
        }
        return ans;
    }
};