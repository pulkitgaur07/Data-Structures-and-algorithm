// Question : Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

// Examples:

// Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
// Output: 4
// Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
// Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
// Output: 6
// Explanation: The longest span with same sum is from index 1 to 6 following zero based indexing.
// Constraints:
// 1 <= a1.size() = a2.size() <= 106
// 0 <= a1[i], a2[i] <= 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        int ans = 0;
        unordered_map<int, int> ind;
        ind[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (a1[i]-a2[i]);
            if(ind.find(sum) != ind.end())
                ans = max(ans, i-ind[sum]);
            else
                ind[sum] = i;
        }
        return ans;
    }
};