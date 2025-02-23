// Question : Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

// A parenthesis string is valid if:

// For every opening parenthesis, there is a closing parenthesis.
// The closing parenthesis must be after its opening parenthesis.

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxLength(string &S){
        int n = S.size();
        int open = 0, close = 0, ans = 0;

        // Left to Right
        for (int i = 0; i < n; i++){
            if (S[i] == '('){
                open++;
            }
            else{
                close++;
            }
            if (open == close){
                ans = max(ans, open * 2);
            }
            else if (close > open){
                open = close = 0;
            }
        }

        // Right to Left
        open = close = 0;
        for (int i = n - 1; i >= 0; i--){
            if (S[i] == '('){
                open++;
            }
            else{
                close++;
            }
            if (open == close){
                ans = max(ans, open * 2);
            }
            else if (open > close){
                open = close = 0;
            }
        }

        return ans;
    }
};