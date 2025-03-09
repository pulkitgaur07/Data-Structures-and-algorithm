// Question : Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

// Examples

// Input: s = "abaab"
// Output: 3
// Explanation: All palindromic substrings are : "aba" , "aa" , "baab".

// Input: s = "aaa"
// Output: 3
// Explanation: All palindromic substrings are : "aa", "aa", "aaa".

// Input: s = "abbaeae"
// Output: 4
// Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".

// Constraints:
// 2 ≤ s.size() ≤ 103
// string contains only lowercase english characters

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach

class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int countPS(string &s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if((j-i+1) >= 2)
                if(isPalindrome(i,j,s)){
                    ans++;
                }
            }
        }
        return ans;
    }
};