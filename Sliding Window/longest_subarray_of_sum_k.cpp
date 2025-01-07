#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestSubarrayOfSizeK(vector<int>& arr, int k){
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0, maxi = 0;
    while(j < n){
        sum += arr[j];
        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxi = max(maxi,(j-i+1));
            j++;
        }
        else if(sum > k){
            while(sum > k && j < n){
                sum -= arr[i];
                i++;
            }
            j++;
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
    int k;
    cin>>k;
    int ans = LongestSubarrayOfSizeK(arr,k);
    cout<<"Longest Subarray Of Size K is : "<<ans<<endl;
    return 0;
}