// Question : Given two positive integers n and k, determine the highest value of x such that kx divides n! (n factorial) completely (i.e., n % (kx) == 0).

// Examples :

// Input: n = 7, k = 2
// Output: 4
// Explanation: 7! = 5040, and 24 = 16 is the highest power of 2 that divides 5040.
// Input: n = 10, k = 9
// Output: 2
// Explanation: 10! = 3628800, and 9² = 81 is the highest power of 9 that divides 3628800.
// Constraints:
// 1 ≤ n ≤ 105
// 2 ≤ k ≤ 105

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxKPower(int n, int k) {
        vector<bool> isPrime(n + 1, true);
        unordered_map<int, int> primesforK;
        int ans = 1e9;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
        for (int i = 2; i <= k; i++) {
            if (!isPrime[i]) continue;
            int expo = 0;
            while (k % i == 0) {
                k /= i;
                expo++;
            }
            if (expo > 0)
                primesforK[i] = expo;
        }
        for (auto& p : primesforK) {
            int prime = p.first;
            int freq = p.second;
            int cnt = 0;
            for (long long power = prime; power <= n; power *= prime)
                cnt += n / power;
            ans = min(ans, cnt / freq);
        }
        return ans;
    }
};