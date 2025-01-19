#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;
        unordered_map<int,int>mp;
        vector<int>ans;
        while(j<n){
            mp[arr[j]]++;
            if((j-i+1) < k){
                j++;
            }
            else if((j-i+1) == k){
                int val = mp.size();
                ans.push_back(val);
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                i++; j++;
            }
        }
        return ans;
    }
};