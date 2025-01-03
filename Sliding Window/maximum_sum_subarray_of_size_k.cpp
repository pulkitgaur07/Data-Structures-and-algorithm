#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaximumSumSubarrayOfSizeK(vector<int>& arr, int k){
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0, maxSum = INT_MIN;
    while(j < n){
        sum += arr[j];
        if((j-i+1) < k){
            j++;
        }
        else if((j-i+1) == k){
            maxSum = max(maxSum,sum);
            sum -= arr[i];
            i++; j++;
        }
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = MaximumSumSubarrayOfSizeK(arr,k);
    cout<<"Maximum Sum Subarray Of Size K is : "<<ans<<endl;
    return 0;
}