// Question : Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

// The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

// Examples :

// Input: s = "abbccc", k = 2
// Output: 6
// Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
// Input: s = "aaab", k = 2
// Output: 2
// Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
// Constraints:
// 0 ≤ k ≤ s.length() ≤ 105 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        int n = s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]){
                pq.push(freq[i]);
            }
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            top--;
            pq.push(top);
        }
        int ans = 0;
        while(pq.size()){
            int val = pq.top();
            pq.pop();
            ans += (val*val);
        }
        return ans;
    }
};