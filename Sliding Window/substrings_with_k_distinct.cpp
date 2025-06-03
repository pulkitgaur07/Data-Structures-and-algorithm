// Question : Given a string consisting of lowercase characters and an integer k, the task is to count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

// Examples :

// Input: s = "abc", k = 2
// Output: 2
// Explanation: Possible substrings are ["ab", "bc"]
// Input: s = "aba", k = 2
// Output: 3
// Explanation: Possible substrings are ["ab", "ba", "aba"]
// Input: s = "aa", k = 1
// Output: 3
// Explanation: Possible substrings are ["a", "a", "aa"]
// Constraints:
// 1 ≤ s.size() ≤ 106
// 1 ≤ k ≤ 26

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstringAtleastK(string& s, int k){
        int n = s.size();
        int ans = 0;
        int i = 0, j = 0, f = 0;
        vector<int>c(26,0);
        for(int i = 0; i < n; i++){
            while(j < n && f < k){
                c[s[j] - 'a']++;
                if(c[s[j] - 'a'] == 1){
                    f++;
                }
                j++;
            }
            if(f >= k){
                ans += n-j+1;
            }
            c[s[i] - 'a']--;
            if(c[s[i] - 'a'] == 0){
                f--;
            }
        }
        return ans;
        
    }
    int countSubstr(string& s, int k) {
        int ans = countSubstringAtleastK(s, k) - countSubstringAtleastK(s, k+1);
        return ans;
    }
};