// Question : You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

// Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find Nearest Smaller To Left
    void NearestSmallerToLeft(vector<int> &l,vector<int> &arr){
        int n = arr.size();
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({arr[i],i});
            }
            else if(st.top().first >= arr[i]){
                while(!st.empty() && (st.top().first >= arr[i])){
                    st.pop();
                }
                if(!st.empty()){
                    l[i] = st.top().second;
                }
                st.push({arr[i],i});
            }
            else{
                l[i] = st.top().second;
                st.push({arr[i],i});
            }
        }
    }
    
    // Function to find Nearest Smaller To Right
    void NearestSmallerToRight(vector<int> &r,vector<int> &arr){
        int n = arr.size();
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({arr[i],i});
            }
            else if(st.top().first >= arr[i]){
                while(!st.empty() && (st.top().first >= arr[i])){
                    st.pop();
                }
                if(!st.empty()){
                    r[i] = st.top().second;
                }
                st.push({arr[i],i});
            }
            else{
                r[i] = st.top().second;
                st.push({arr[i],i});
            }
        }
    }
    // Function to find the maximum rectangular area of histogram
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int>l(n,-1),r(n,n);
        NearestSmallerToLeft(l,arr);
        NearestSmallerToRight(r,arr);
        int ans = arr[0];
        for(int i=0;i<n;i++){
            ans = max(ans,arr[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};