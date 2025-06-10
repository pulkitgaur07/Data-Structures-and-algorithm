// Question : Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

// Examples:

// Input: s = "geek"
// Output: 6
// Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg") 
// Input: s = "aaaa"
// Output: 1
// Explanation: Only one distinct string is possible after one swap(i.e "aaaa")
// Constraints:
// 2 ≤ s.size() ≤ 104

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStrings(string &s) {
        vector<int>freq(26,0);
        int n=s.size();
        for(int i = 0;i <n;i++) {
            freq[s[i]-'a']++;
        }
        int count=0;
        bool flag=false;
        for(int i= 0; i < n; i++){
            if(freq[s[i]-'a']>0)
                count+=(n-freq[s[i]-'a']);
            if(freq[s[i]-'a']>1)
                flag=true;
        }
        count/=2;
        return flag?count+1:count;
    }
};