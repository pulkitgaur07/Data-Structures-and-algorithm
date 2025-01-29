// Question :

// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        int preXor=0,count=0;
        for(int i=0;i<arr.size();i++){
            preXor^=arr[i];
            if(preXor==k) count++;
            if(mp.find(preXor^k)!=mp.end()) count+=mp[preXor^k];
            mp[preXor]++;
        }
        return count;
    }
};