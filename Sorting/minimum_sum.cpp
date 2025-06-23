// Question : Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

// Examples :

// Input: arr[] = [6, 8, 4, 5, 2, 3]
// Output: "604"
// Explanation: The minimum sum is formed by numbers 358 and 246.
// Input: arr[] = [5, 3, 0, 7, 4]
// Output: "82"
// Explanation: The minimum sum is formed by numbers 35 and 047.
// Input: arr[] = [9, 4]
// Output: "13"
// Explanation: The minimum sum is formed by numbers 9 and 4.
// Constraints:
// 2 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 9

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        if(n==1){
            if(arr[0] == 0) return "";
            else{
                char ch = arr[0]+'0';
                return string(1,ch);
            };
        }
        sort(arr.begin(),arr.end());
        string a = "", b = "";
        for(int i=0;i<n;i++){
            char ch = arr[i]+'0';
            if(i&1){
                b += ch;
            }
            else{
                a += ch;
            }
        }
        string ans = "";
        int i,j;
        if(n&1){
            i = n/2;
            j = (n-2)/2;
        }
        else{
            i = (n-1)/2;
            j = (n-1)/2;
        }
        int x = 0, y = 0, carry = 0;
        while(i>=0 || j>=0){
            if(i>=0) x = a[i]-'0';
            if(j>=0) y = b[j]-'0';
            int val = (x+y+carry);
            ans += (val%10)+'0';
            carry = val/10;
            x = 0, y = 0;
            i--; j--;
        }
        if(carry) ans += carry+'0';
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i] == '0') continue;
            else{
                string res = ans.substr(0,i+1);
                reverse(res.begin(),res.end());
                return res;
            };
        }
        return "";
    }
};