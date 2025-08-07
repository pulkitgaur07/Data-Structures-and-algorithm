// Question : Given an array arr[] of time strings in 24-hour clock format "HH:MM:SS", return the minimum difference in seconds between any two time strings in the arr[].
// The clock wraps around at midnight, so the time difference between "23:59:59" and "00:00:00" is 1 second.

// Examples:

// Input: arr[] = ["12:30:15", "12:30:45"]
// Output: 30
// Explanation: The minimum time difference is 30 seconds.
// Input: arr[] = ["00:00:01", "23:59:59", "00:00:05"]
// Output: 2
// Explanation: The time difference is minimum between "00:00:01" and "23:59:59".
// Constraints:
// 2 ≤ arr.size() ≤ 105
// arr[i] is in "HH:MM:SS" format.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDifference(vector<string> &arr) {
        int n=arr.size();
        vector<int>t(n);
        for(int i=0;i<n;i++){
            int h,m,s;
            string temp=arr[i];
            h=10*(temp[0]-'0')+(temp[1]-'0');
            m=10*(temp[3]-'0')+(temp[4]-'0');
            s=10*(temp[6]-'0')+(temp[7]-'0');
            
            int total=60*60*h+60*m+s;
            t[i]=total;
        }
        sort(t.begin(),t.end());
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,t[i]-t[i-1]);
        }
        ans=min(ans,23*60*60+59*60+60-t[n-1]+t[0]);
        return ans;
    }
};