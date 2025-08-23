// Question : Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i], k ≤ 103

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isOkk(vector<int> &arr, int m, int k){
        int count=1, sum=0;
        for(auto z: arr){
            sum+=z;
            if(sum>m){
                count++;
                sum=z;
            }
        }
        return count<=k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k>n)
          return -1; 
        int sum=0, maxi = INT_MIN;
        for(auto z: arr){
            sum+=z;
            maxi = max(maxi, z);
        }
        int l=maxi, r=sum, ans=INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isOkk(arr, m, k)){
                ans = min(ans, m);
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};