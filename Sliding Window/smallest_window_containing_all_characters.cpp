// Question : Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
// If there are multiple such substring of the same length found, return the one with the least starting index.

// Examples:

// Input: s = "timetopractice", p = "toc"
// Output: "toprac"
// Explanation: "toprac" is the smallest substring in which "toc" can be found.
// Input: s = "zoomlazapzo", p = "oza"
// Output: "apzo"
// Explanation: "apzo" is the smallest substring in which "oza" can be found.
// Input: s = "zoom", p = "zooe"
// Output: ""
// Explanation: No substring is present containing all characters of p.
// Constraints: 
// 1 ≤ s.length(), p.length() ≤ 106
// s, p consists of lowercase english letters

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        int n=s.size(),m=p.size();
        int start=-1,end=-1,mini=INT_MAX;
        unordered_map<char,int>mp;
        for(char &ch:p){
            mp[ch]++;
        }
        if(m>n) return "";
        int i=0,j=0;
        int count=m;
        while(j<n){
            if(mp[s[j]]>0){
                count--;
            }
            mp[s[j]]--;
            if(count>0) {
                j++;
            } else if(count==0){
                if(j-i+1<mini){
                    mini=min(mini,j-i+1);
                    start=i,end=j;
                } 
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) count++;
                        if(count==1){
                            if(j-i+1<mini){
                                mini=min(mini,j-i+1);
                                start=i,end=j;
                            } 
                        }
                    }
                    
                    i++;
                }
                
                j++;
            }
        }
        if(start==-1 && end==-1) return "";
        return s.substr(start,end-start+1);
    }
};