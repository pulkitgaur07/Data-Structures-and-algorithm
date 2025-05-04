// Question : Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

// Example:

// Input: str = "aabcbcdbca"
// Output: 4
// Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
// Input: str = "aaab"
// Output: 2
// Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
// Input: str = "geeksforgeeks"
// Output: 8
// Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks". 
// Constraints:
// 1 ≤ str.size() ≤ 105
// str contains only lower-case english alphabets.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubString(string& str) {
        int n = str.size();
        vector<int>flag1(26,0);
        for(int i=0;i<n;i++){
            flag1[str[i]-'a']++;
        }
        int distinct = 0;
        for(int i=0;i<26;i++){
            if(flag1[i]){
                distinct++;
            }
        }
        vector<int>flag2(26,0);
        int i=0;
        int ans = n;
        for(int j=0;j<n;j++){
            flag2[str[j]-'a']++;
            int newDistinct = 0;
            for(int k=0;k<26;k++){
                if(flag2[k]){
                    newDistinct++;
                }
            }
            while(newDistinct == distinct){
                ans = min(ans,(j-i+1));
                flag2[str[i]-'a']--;
                if(flag2[str[i]-'a'] == 0){
                    newDistinct--;
                }
                i++;
            }
        }
        return ans;
    }
};