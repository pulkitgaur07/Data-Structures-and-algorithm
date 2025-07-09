// Question : Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.

// Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

// Examples:

// Input: arr[] = [3, 1, 2, 4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
// Input: arr[] = [71, 55, 82, 55]
// Output: 593
// Explanation: The sum of the minimum of all the subarrays is 593.
// Constraints:
// 1 ≤ arr.size() ≤ 3*104
// 1 ≤ arr[i] ≤ 103

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        vector<int>ngr,ngl;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ngr.push_back(n);
            }
            else if(arr[st.top()] >= arr[i]){
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ngr.push_back(n);
                }
                else{
                    ngr.push_back(st.top());
                }
            }
            else{
                ngr.push_back(st.top());
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(st.empty()){
                ngl.push_back(-1);
            }
            else if(arr[st.top()] > arr[i]){
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ngl.push_back(-1);
                }
                else{
                    ngl.push_back(st.top());
                }
            }
            else{
                ngl.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ngr.begin(),ngr.end());
        for(int i=0;i<n;i++){
            ans += (arr[i]*((ngr[i]-i)*(i-ngl[i])));
        }
        return ans;
    }
};