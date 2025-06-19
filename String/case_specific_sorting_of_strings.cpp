// Question : Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Examples :

// Input: s = "GEekS"
// Output: EGekS
// Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
// Input: s = "XWMSPQ"
// Output: MPQSWX
// Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.
// Constraints:
// 1 ≤ s.length() ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string caseSort(string& s) {
        int n=s.size();
        string ans="";
        int a[26]={0},b[26]={0},k[n]={0};
        for(int i=0;i<n;i++){
            if(s[i]<='Z'){
                a[s[i]-'A']++;
                k[i]+=1;
            }
            else{
                b[s[i]-'a']++;
            }
        }
        for(int i=0;i<n;i++){
            if(k[i]){
                for(int j=0;j<26;j++){
                 if(a[j]){
                     ans+=j+'A';
                     a[j]--;
                     break;
                 }
                }
            }
            else{
                for(int j=0;j<26;j++){
                 if(b[j]){
                     ans+=j+'a';
                     b[j]--;
                     break;
                 }
                }
            }
        }
        return ans;
    }
};