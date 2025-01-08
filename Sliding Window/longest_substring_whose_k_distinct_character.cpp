#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestSubstringWhoseKDistinctCharacter(string &s, int k){
    int n = s.size();
    int i = 0, j = 0;
    map<char,int>mp;
    int maxi = 0;
    while(j < n){
        mp[s[j]]++;
        if(mp.size() < k){
            j++;
        }
        else if(mp.size() == k){
            maxi = max(maxi,(j-i+1));
            j++;
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int ans = LongestSubstringWhoseKDistinctCharacter(s,k);
    cout<<"Longest Substring Whose K Distinct Character is : "<<ans<<endl;
    return 0;
}