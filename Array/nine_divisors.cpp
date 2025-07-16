// Question : Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.

// Examples :

// Input: n = 100
// Output: 2
// Explanation: Numbers which have exactly 9 divisors are 36 and 100.
// Input: n = 200
// Output: 3
// Explanation: Numbers which have exactly 9 divisors are 36, 100, 196. 
// Constraints:
// 1 ≤ n ≤ 109

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(int N) { 
        map<int,int> mp;
        for(int i=2;i<=sqrt(N);i++) { 
            while(N%i==0) { 
                mp[i]++; 
                N=N/i; 
            }
        } 
        if(N!=1) mp[N]++;   
        if(mp.size()==1) { 
            auto it=mp.begin(); 
            if(it->second*2+1==9) return 1; 
            return 0;
        } 
        for(auto it:mp) {   
            if(it.second>1) return 0; 
        }
        if(mp[N]>1) return 0; 
        return mp.size()==2;
    }
    int countNumbers(int n) {
        int dem=0;
        for(int i=2;i<=sqrt(n);i++) {  
            if(check(i)) dem++;
        } 
        return dem;
    }
};