#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int CountOccurancesOfAnagram(string &s, string &p){
    int n = s.size();
    int k = p.size();
    unordered_map<char,int>mp;
    int i = 0, j = 0;
    for(auto &x : p){
        mp[x]++;
    }
    int count = mp.size();
    int ans = 0;
    while(j < n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                count--;
            }
        }
        if((j-i+1) < k){
            j++;
        }
        else if((j-i+1) == k){
            if(count == 0){
                ans++;
            }
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] == 1){
                    count++;
                }
            }
            i++; j++;
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    string p;
    cin>>p;
    int ans = CountOccurancesOfAnagram(s,p);
    cout<<"Count Occurances Of Anagram is: "<<ans<<endl;
    return 0;
}