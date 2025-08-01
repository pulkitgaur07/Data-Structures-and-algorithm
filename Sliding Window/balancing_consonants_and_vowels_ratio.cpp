// Question : You are given an array of strings arr[], where each arr[i] consists of lowercase english alphabets. You need to find the number of balanced strings in arr[] which can be formed by concatinating one or more contiguous strings of arr[].
// A balanced string contains the equal number of vowels and consonants. 

// Examples:

// Input: arr[] = ["aeio", "aa", "bc", "ot", "cdbd"]
// Output: 4
// Explanation: arr[0..4], arr[1..2], arr[1..3], arr[3..3] are the balanced substrings with equal consonants and vowels.
// Input: arr[] = ["ab", "be"]
// Output: 3
// Explanation: arr[0..0], arr[0..1], arr[1..1] are the balanced substrings with equal consonants and vowels.
// Input: arr[] = ["tz", "gfg", "ae"]
// Output: 0
// Explanation: There is no such balanced substring present in arr[] with equal consonants and vowels.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i].size() ≤ 105
// Total number of lowercase english characters in arr[] is lesser than 105.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return 1;
        }
        return -1;
    }
    int countBalanced(vector<string>& arr) {
        int n = arr.size();
        map<int,int>mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(auto i : arr){
            for(auto j : i){
                sum += isVowel(j);
            }
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};