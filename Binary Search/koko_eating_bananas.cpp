// Question : Koko is given an array arr[], where each element represents a pile of bananas. She has exactly k hours to eat all the bananas.

// Each hour, Koko can choose one pile and eat up to s bananas from it.

// If the pile has atleast s bananas, she eats exactly s bananas.

// If the pile has fewer than s bananas, she eats the entire pile in that hour.

// Koko can only eat from one pile per hour.


// Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.

// Examples:

// Input: arr[] = [5, 10, 3], k = 4
// Output: 5
// Explanation: Koko eats at least 5 bananas per hour to finish all piles within 4 hours, as she can consume each pile in 1 + 2 + 1 = 4 hours.
// Input: arr[] = [5, 10, 15, 20], k = 7
// Output: 10
// Explanation: At 10 bananas per hour, Koko finishes in 6 hours, just within the limit 7.
// Constraint:
// 1 ≤ arr.size() ≤ 105 
// 1 ≤ arr[i] ≤ 106
// arr.size() ≤ k ≤ 106

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int curr = 0;
            for(int i = 0; i < arr.size(); i++){
                curr += ceil((double)arr[i]/mid);
            }
            if(curr <= k){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};