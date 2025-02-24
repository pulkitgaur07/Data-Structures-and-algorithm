// Question : Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n= arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(arr[i]);
            }
            else if(st.top() <= arr[i]){
                while(!st.empty() && (st.top() <= arr[i])){
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