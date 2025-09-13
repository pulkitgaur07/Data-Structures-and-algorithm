// Question : Given a board of dimensions n × m that needs to be cut into n*m squares. The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

// x[]: Cutting costs along the vertical edges (length-wise).
// y[]: Cutting costs along the horizontal edges (width-wise).
// Find the minimum total cost required to cut the board into squares optimally.

// Examples:

// Input: n = 4, m = 6, x[] = [2, 1, 3, 1, 4], y[] = [4, 1, 2]
// Output: 42
// Explanation:

// Initially no. of horizontal segments = 1 & no. of vertical segments = 1.
// Optimal way to cut into square is:
// • Pick 4 (from x) -> vertical cut, Cost = 4 × horizontal segments = 4,
//   Now, horizontal segments = 1, vertical segments = 2.
// • Pick 4 (from y) -> horizontal cut, Cost = 4 × vertical segments = 8,
//   Now, horizontal segments = 2, vertical segments = 2.
// • Pick 3 (from x) -> vertical cut, Cost = 3 × horizontal segments = 6,
//   Now, horizontal segments = 2, vertical segments = 3.
// • Pick 2 (from x) -> vertical cut, Cost = 2 × horizontal segments = 4,
//   Now, horizontal segments = 2, vertical segments = 4.
// • Pick 2 (from y) -> horizontal cut, Cost = 2 × vertical segments = 8,
//   Now, horizontal segments = 3, vertical segments = 4.
// • Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 3,
//   Now, horizontal segments = 3, vertical segments = 5.
// • Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 3,
//   Now, horizontal segments = 3, vertical segments = 6.
// • Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 6,
//   Now, horizontal segments = 4, vertical segments = 6.
// So, the total cost = 4 + 8 + 6 + 4 + 8 + 3 + 3 + 6 = 42.
// Input: n = 4, m = 4, x[] = [1, 1, 1], y[] = [1, 1, 1]
// Output: 15
// Explanation: 

// Initially no. of horizontal segments = 1 & no. of vertical segments = 1.
// Optimal way to cut into square is: 
// • Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
//   Now, horizontal segments = 2, vertical segments = 1.
// • Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
//   Now, horizontal segments = 3, vertical segments = 1.
// • Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
//   Now, horizontal segments = 4, vertical segments = 1.
// • Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
//   Now, horizontal segments = 4, vertical segments = 2.
// • Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
//   Now, horizontal segments = 4, vertical segments = 3.
// • Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
//   Now, horizontal segments = 4, vertical segments = 4
// So, the total cost = 1 + 1 + 1 + 4 + 4 + 4 = 15.
// Constraints:
// 2 ≤ n, m ≤ 103
// 1 ≤ x[i], y[j] ≤103

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        int hori = 1;
        int ver = 1;
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        int sum = 0;
        
        int n1 = x.size();
        int n2 = y.size();
        
        int i=n1-1;
        int j=n2-1;
        
        while(i>=0 && j>=0){
            if(x[i]>=y[j]){
                sum += x[i]*hori;
                ver++;
                i--;
            } else{
                sum += y[j]*ver;
                hori++;
                j--;
            }
        }
        
        while(i>=0){
            sum += x[i]*hori;
            ver++;
            i--;
        }
        
        while(j>=0){
            sum += y[j]*ver;
            hori++;
            j--;
        }
        
        return sum;
    }
};
