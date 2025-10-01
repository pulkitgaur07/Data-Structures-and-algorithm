// Question : Given an array arr[] that may contain duplicates. Find all possible distinct permutations of the array in sorted order.
// Note: A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

// Examples:

// Input: arr[] = [1, 3, 3]
// Output: [[1, 3, 3], [3, 1, 3], [3, 3, 1]]
// Explanation: These are the only possible distinct permutations for the given array.
// Input: arr[] = [2, 3]
// Output: [[2, 3], [3, 2]]
// Explanation: These are the only possible distinct permutations for the given array.
// Constraints:
// 1 ≤ arr.size() ≤ 9

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution {
  public:
    void dfs(int i,int n,vector<int> &arr, set<vector<int>> &st){
        if(i==n){
            st.insert(arr);
            return;
        }
        for(int j=i;j<n;j++){
            swap(arr[i],arr[j]);
            dfs(i+1,n,arr,st);
            swap(arr[i],arr[j]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>>st;
        dfs(0,n,arr,st);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
