#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestSubstringWithNoRepeatingCharacter(string &s){
    int n = s.size();
    int i = 0, j = 0;
    int maxi = 0;
    map<char,int>mp;
    while(j < n){
        mp[s[j]]++;
        if(mp.size() < (j-i+1)){
            while(mp.size() < (j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        else if(mp.size() == (j-i+1)){
            maxi = max(maxi,(j-i+1));
            j++;
        }
    }
    return maxi;
}

int main(){
    string s;
    cin>>s;
    int ans = LongestSubstringWithNoRepeatingCharacter(s);
    cout<<"Longest Substring With No Repeating Character is : "<<ans<<endl;
    return 0;
}