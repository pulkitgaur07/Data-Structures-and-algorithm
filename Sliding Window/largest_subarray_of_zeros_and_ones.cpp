// Problem Statement : 

// Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LargestSubarrayOfZerosAndOnes(vector<int>& arr){
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0, maxi = 0;
    unordered_map<int,int>mp;
    mp[0] = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            sum += -1;
        }
        else{
            sum += 1;
        }
        if(mp.find(sum) != mp.end()){
            maxi = max(maxi,i-mp[sum]);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = LargestSubarrayOfZerosAndOnes(arr);
    cout<<"Largest Subarray Of Zeros And Ones is : "<<ans<<endl;
    return 0;
}