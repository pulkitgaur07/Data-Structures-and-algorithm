// Question : Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). The task is to return the kth smallest element in the m * n multiplication table.

// Examples :

// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: 

// The 5th smallest element is 3. 
// Input: m = 2, n = 3, k = 6
// Output: 6 
// Explanation: [1, 2, 3][2, 4, 6]. The 6th smallest element is 6.
// Constraints:
// 1 <= m, n <= 3 * 104
// 1 <= k <= m * n

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n); 
            }
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};