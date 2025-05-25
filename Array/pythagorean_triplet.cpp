// Question : Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

// Examples:

// Input: arr[] = [3, 2, 4, 6, 5]
// Output: true
// Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.
// Input: arr[] = [3, 8, 5]
// Output: false
// Explanation: No such triplet possible.
// Input: arr[] = [1, 1, 1]
// Output: false
// Constraints:
// 1 <= arr.size() <= 105
// 1 <= arr[i] <= 103

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        vector<int>elements(maxi+1,0);
        for(int i:arr){
            elements[i]++;
        }
        for(int i=1;i<=maxi;i++){
            for(int j=i+1;j<=maxi;j++){
                if(elements[i] && elements[j]){
                    int a=i,b=j;
                    int right=(a*a) + (b*b);
                    int c=sqrt(right);
                    if(c<=maxi && (c*c)==right && elements[c]) 
                        return true;
                }
            }
        }
        return false;
    }
};