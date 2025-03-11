// Question : Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity - O(n*n)
// Space Complexity - O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int a=0, b=0, c=0;
            for(int j=i;j<n;j++){
                if(s[j] == 'a') a++;
                else if(s[j] == 'b') b++;
                else c++;
                if(a && b && c){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Brute Force Approach
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0, j=0, a=0, b=0, c=0;
        int ans = 0;
        while(j<n){
            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else c++;
            if(a && b && c){
                while(a && b && c && i<=j){
                    ans += (n-j);
                    if(s[i] == 'a') a--;
                    else if(s[i] == 'b') b--;
                    else c--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};