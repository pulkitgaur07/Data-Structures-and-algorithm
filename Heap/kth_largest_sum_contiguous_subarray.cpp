// Question : Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.

// Examples:

// Input: arr[] = [3, 2, 1], k = 2 
// Output: 5
// Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.
// Input: arr[] = [2, 6, 4, 1], k = 3
// Output: 11
// Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.
// Constraints:
// 1 <= arr.size() <= 1000
// 1 <= k <= (n*(n+1))/2
// -105 <= arr[i] <= 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                pq.push(sum);
            }
        }
        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};