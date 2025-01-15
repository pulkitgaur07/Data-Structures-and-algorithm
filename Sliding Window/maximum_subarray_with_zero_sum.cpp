#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaximumSubarrayWithZeroSum(vector<int>& arr){
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0, maxi = 0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == 0){
            maxi = i+1;
        }
        else{
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi,i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
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
    int ans = MaximumSubarrayWithZeroSum(arr);
    cout<<"Maximum Subarray With Zero Sum is : "<<ans<<endl;
    return 0;
}