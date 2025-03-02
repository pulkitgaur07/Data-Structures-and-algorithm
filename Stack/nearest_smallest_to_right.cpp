// Question : Given an array arr[ ] of integers, the task is to find the next smallest element for each element of the array in order of their appearance in the array. Next smallest element of an element in the array is the nearest element on the right which is smaller than the current element.
// If there does not exist next smallest of current element, then next smallest element for current element is -1. For example, next smallest of the last element is always -1.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find Nearest Smaller To Right
    vector<int> NearestSmallerToLeft(vector<int> &l,vector<int> &arr){
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i++){
            if(st.empty()){
                st.push(arr[i]);
            }
            else if(st.top() >= arr[i]){
                while(!st.empty() && (st.top() >= arr[i])){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top();
                }
                st.push(arr[i]);
            }
            else{
                ans[i] = st.top();
                st.push(arr[i]);
            }
        }
        return ans;
    }
};