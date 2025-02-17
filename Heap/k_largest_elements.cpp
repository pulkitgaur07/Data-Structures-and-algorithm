// Question : Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans(k);
        int i = k-1;
        while(pq.size()){
            ans[i] = pq.top();
            pq.pop();
            i--;
        }
        return ans;
    }
};