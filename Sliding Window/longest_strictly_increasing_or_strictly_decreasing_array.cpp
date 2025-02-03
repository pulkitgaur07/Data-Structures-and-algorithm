// Question : You are given an array of integers nums.Return the length of the longest subarray of nums which is either strictly increasing orstrictly decreasing.

#include <iostream>
#include <bits/stdc++.h>
           using namespace std;

int longestStrictlyIncreasingOrDecreasingArray(vector<int> &nums)
{
    int n = nums.size();
    int ans = 1, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = longestStrictlyIncreasingOrDecreasingArray(nums);
    return 0;
}