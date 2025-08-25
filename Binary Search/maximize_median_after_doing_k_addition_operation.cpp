// Question : Given an array arr[] consisting of positive integers and an integer k. You are allowed to perform at most k operations, where in each operation, you can increment any one element of the array by 1. Determine the maximum possible median of the array that can be achieved after performing at most k such operations.

// Note: The median of an array is defined as the middle element when the array (after sorting) has an odd size, or the average of the two middle elements when the array (after sorting) has an even size.

// Examples:

// Input: arr[] = [1, 3, 4, 5], k = 3
// Output: 5
// Explanation: We can add +2 to the second element and +1 to the third element to get the array [1, 5, 5, 5]. After sorting, the array remains [1, 5, 5, 5]. Since the length is even, the median is (5 + 5) / 2 = 5.
// Input: arr[] = [1, 3, 6, 4, 2], k = 10
// Output: 7
// Explanation: After applying operations optimally, we can transform the array to [1, 3, 7, 7, 7] (one possible way). Sorted array becomes [1, 3, 7, 7, 7]. Since the length is odd, the median is the middle element 7.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i], k ≤ 109

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int n, vector<int> &arr, long long mid, long long k)
    {
        long long need = 0;
        int half = n / 2;
        if (n % 2)
        { // odd
            need += max(0LL, mid - (long long)arr[half]);
        }
        else
        { // even → need to make average ≥ mid
            need += max(0LL, 2 * mid - ((long long)arr[half] + arr[half - 1]));
        }
        for (int i = half + 1; i < n; i++)
        {
            need += max(0LL, mid - (long long)arr[i]);
            if (need > k)
                return false; // early stop
        }
        return need <= k;
    }
    int maximizeMedian(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long l = arr[0];
        long long r = arr[n - 1] + k;
        long long maxMedian = l;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (isPossible(n, arr, mid, k))
            {
                maxMedian = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return int(maxMedian);
    }
};