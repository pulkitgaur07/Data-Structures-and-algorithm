// Question : Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

// Examples:

// Input: arr[] = [1, 2, 3, 4, 1], k = 2
// Output: 3
// Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
// Input: arr[] = [6, 5, 3, 4], k = 2
// Output: 4
// Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
// Constraints:
// 1 <= arr.size() <= 106
// 1 <= arr[i] <= 106
// 0 <= k <= 106

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int longestSubarray(vector<int> &arr, int k) {
    int n = arr.size();
    map<int,int>mp;
    mp[0] = -1;
    int cnt = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > k) cnt++;
        else cnt--;
        if(cnt>0) ans = i+1;
        if(mp.find(cnt-1) != mp.end()){
            ans = max(ans,i-mp[cnt-1]);
        }
        if(mp.find(cnt) == mp.end()){
            mp[cnt] = i;
        }
    }
    return ans;
}
};