// Question : Given an array arr[], where each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
// Keep in mind the following conditions :

// Each policeman can catch only one thief.
// A policeman cannot catch a thief who is more than k units away from him.
// Examples:

// Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
// Output: 2
// Explanation: Maximum 2 thieves can be caught. First policeman catches first thief and second police man can catch either second or third thief.
// Input: arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
// Output: 3
// Explanation: Maximum 3 thieves can be caught.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ k ≤ 1000
// arr[i] = 'P' or 'T'

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int i=0, j=0, ans=0;
        while(i<n && j<n){
            if(arr[i] == 'T' && arr[j] == 'P'){
                if(abs(i-j) <= k){
                    ans++;
                    i++;
                    j++;
                }
                else{
                    i<j? i++ : j++;
                }
            }
            else{
                while(i<n && arr[i] == 'P'){
                    i++;
                }
                while(j<n && arr[j] == 'T'){
                    j++;
                }
            }
        }
        return ans;
    }
};