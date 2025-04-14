// Question : A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

// However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

// A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

// Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
// Input: words[] = ["caa", "aaa", "aab"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "cab".
// The pair "caa" and "aaa" suggests 'c' appears before 'a'.
// The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
// So, 'c' → 'a' → 'b' is a valid ordering.
// Input: words[] = ["ab", "cd", "ef", "ad"]
// Output: ""
// Explanation: No valid ordering of letters is possible.
// The pair "ab" and "ef" suggests "a" appears before "e".
// The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
// Constraints:
// 1 ≤ words.length ≤ 500
// 1 ≤ words[i].length ≤ 100
// words[i] consists only of lowercase English letters.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        map<char,vector<char>> adj;
        vector<bool> freq1(26,0),freq2(26,0);
        vector<int> inDegree(26,0);
        for(int i=0;i<n-1;i++){
            int sz1 = words[i].length();
            int sz2 = words[i+1].length();
            for(int j=0;j<sz1;j++){
                if(j>=sz2) return "";
                if(words[i][j]!=words[i+1][j]) {
                    adj[words[i][j]].push_back(words[i+1][j]);
                    freq1[words[i][j]-'a']=1;
                    freq1[words[i+1][j]-'a']=1;
                    inDegree[words[i+1][j]-'a']++;
                    break;
                }
            }
        }
        string ans = "";
        queue<char> q;
        int cnt =0;
        for(int i=0;i<26;i++){
            if(freq1[i]){
                cnt++;
                if(inDegree[i]==0) q.push(i+'a'); 
            }
        }
        while(!q.empty()){
            char u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto &v:adj[u]){
                inDegree[v-'a']--;
                if(inDegree[v-'a'] == 0) { q.push(v);}
            }
        }
        if(ans.length() != cnt) return "";
        for(auto &ele:words){
            for(auto &c:ele) freq2[c-'a']=1;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]==0 and freq2[i]==1) ans.push_back(i+'a');
        }
        return ans;
    }
};