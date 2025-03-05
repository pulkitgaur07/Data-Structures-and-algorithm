#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> sortAKSortedArray(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                int ele = pq.top();
                ans.push_back(ele);
                pq.pop();
            }
        }
        while(pq.size()){
            int ele = pq.top();
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};