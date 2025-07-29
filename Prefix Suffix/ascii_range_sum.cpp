// Question : Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
// Return all such non-zero sums (order does not matter).

// Examples:

// Input: s = "abacab"
// Output: [293, 294]
// Explanation: characters 'a' and 'b' appear more than once:
// 'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
// 'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.
// Input: s = "acdac"
// Output: [197, 199]
// Explanation: characters 'a' and 'c' appear more than once:
// 'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
// 'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.
// Constraints:
// 1 ≤ s.size() ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        vector<int>freq(26,0);
        vector<int>prefix(n+1,0);
        int sum = 0;
        for(int i=0;i<26;i++) freq[i] = i;
        for(int i=0;i<n;i++){
            freq[s[i]-'a'] = i;
            sum += s[i];
            prefix[i+1] = sum;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a'] != -1 && i != freq[s[i]-'a']){
                int val = prefix[freq[s[i]-'a']]-prefix[i+1];
                if(val != 0) ans.push_back(val);
                freq[s[i]-'a'] = -1;
            }
        }
        return ans;
    }
};