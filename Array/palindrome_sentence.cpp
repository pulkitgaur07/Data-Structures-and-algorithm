// Question : Given a single string s, the task is to check if it is a palindrome sentence or not.
// A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).

// Examples:

// Input: s = "Too hot to hoot"
// Output: true
// Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, string s will become "toohottohoot" which is a palindrome.
// Input: s = "Abc 012..## 10cbA"
// Output: true
// Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, string s will become "abc01210cba" which is a palindrome.
// Input: s = "ABC $. def01ASDF"
// Output: false
// Explanation: The processed string becomes "abcdef01asdf", which is not a palindrome.
// Constraints:
// 1 ≤ s.length() ≤ 106

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalinSent(string &s) {
        int n = s.size();
        int i=0,j=n-1;
        while(i<=j){
            while(i<j && !(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')))){
                i++;
            }
            while(i<j && !(((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9')))){
                j--;
            }
            if(i >= j) return true;
            char ch1 = s[i], ch2 = s[j];
            if(s[i]>='A' && s[i]<='Z') ch1 = s[i]-'A'+'a';
            if(s[j]>='A' && s[j]<='Z') ch2 = s[j]-'A'+'a';
            if(ch1 != ch2){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};