// Question : You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

// Note: From dictionary[], any word can be taken any number of times and in any order.

// Examples :

// Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
// Output: true
// Explanation: s can be breakdown as "i like".

// Input: s = "ilikegfg", dictionary[] = ["i", "like", "man", "india", "gfg"]
// Output: true
// Explanation: s can be breakdown as "i like gfg".

// Input: s = "ilikemangoes", dictionary[] = ["i", "like", "man", "india", "gfg"]
// Output: false
// Explanation: s cannot be formed using dictionary[] words.

// Constraints:
// 1 ≤ s.size() ≤ 3000
// 1 ≤ dictionary.size() ≤ 1000
// 1 ≤ dictionary[i].size() ≤ 100

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Tabulation

class Solution {
public:
    bool wordBreak(string &s, vector<string> &dic) {
        int n=s.size(),m=dic.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int k=0;
                for(int l=i;l<n&&k<dic[j].size();l++){
                    if(s[l]==dic[j][k]){
                        k++;
                    }else{
                        break;
                    }
                }
                if(k==dic[j].size()){
                    dp[i]|=dp[i+k];
                }
            }
        }
        return dp[0];
    }
};