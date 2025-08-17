// Question : You are given a number x and array arr[]. Your task is to rearrange the elements of the array according to the absolute difference with x, i.e., an element having minimum difference comes first, and so on.
// Note: If two or more elements are at equal distances arrange them in the same sequence as in the given array.

// Examples:

// Input: x = 7, arr[] = [10, 5, 3, 9, 2]
// Output: [5, 9, 10, 3, 2]
// Explanation: Sorting the numbers according to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.
// Input: x = 6, arr[] = [1, 2, 3, 4, 5]
// Output: [5, 4, 3, 2, 1]
// Explanation: Sorting the numbers according to the absolute difference with 6, we have array elements as 5, 4, 3, 2, 1.
// Constraints:
// 1 ≤ x ≤ 105
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        int n = arr.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-x),{i,arr[i]}});
        }
        int i=0;
        while(!pq.empty()){
            int ele = pq.top().second.second;
            pq.pop();
            arr[i++] = ele;
        }
    }
};