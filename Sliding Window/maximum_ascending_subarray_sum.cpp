// Question : Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
// A subarray is defined as a contiguous sequence of numbers in an array.
// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
    int n=nums.size();
    int maxSum=0, sum=nums[0];
    for(int r=1; r<n; r++){
        if (nums[r]>nums[r-1]) sum+=nums[r];
        else{
            maxSum=max(maxSum, sum);
            sum=nums[r];
        }
    }
    return max(maxSum, sum);
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = maxAscendingSum(nums);
    cout<<ans<<endl;
    return 0;
}