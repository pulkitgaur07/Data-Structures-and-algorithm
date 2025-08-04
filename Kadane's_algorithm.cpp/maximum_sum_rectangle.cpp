// Question : Given a 2D matrix mat[][] with dimensions n×m. Find the maximum possible sum of any submatrix within the given matrix.

// Examples:

// Input: mat[][] = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
// Output: 29
// Explanation: The matrix is as follows and the green rectangle denotes the maximum sum rectangle which is equal to 29.

// Input: mat[][] = [[-1, -2], [-3, -4]]
// Output: -1
// Explanation: Taking only the first cell is the optimal choice.
// Constraints:
// 1 ≤ n, m ≤ 300
// -1000 ≤ mat[i][j] ≤ 1000

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    temp[k] += mat[j][k];
                }
                int currSum = temp[0], maxSum = temp[0];
                for(int k=1;k<m;k++){
                    currSum = max(temp[k],currSum+temp[k]);
                    maxSum = max(maxSum,currSum);
                }
                ans = max(ans,maxSum);
            }
        }
        return ans;
    }
};