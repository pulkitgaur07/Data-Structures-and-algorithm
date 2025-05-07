// Question : There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

// At time t == 4, move from room (0, 0) to room (1, 0) in one second.
// At time t == 5, move from room (1, 0) to room (1, 1) in one second.
// Example 2:

// Input: moveTime = [[0,0,0],[0,0,0]]

// Output: 3

// Explanation:

// The minimum time required is 3 seconds.

// At time t == 0, move from room (0, 0) to room (1, 0) in one second.
// At time t == 1, move from room (1, 0) to room (1, 1) in one second.
// At time t == 2, move from room (1, 1) to room (1, 2) in one second.
// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 3

// Constraints:

// 2 <= n == moveTime.length <= 50
// 2 <= m == moveTime[i].length <= 50
// 0 <= moveTime[i][j] <= 109

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
        pq.push({0,{0,0}});
        int ans = INT_MAX;
        while(pq.size()>0){
            int size = pq.size();
            for(int i =0;i<size;i++){
                auto front = pq.top();
                pq.pop();
                int r = front.second.first;
                int c = front.second.second;
                    int wt = front.first;
                if(r==n-1 && c == m-1){
                    ans = min(ans,wt);
                }
                for(int l=0;l<4;l++){
                    int p1 = r + row[l];
                    int p2 = c + col[l];
                    if( p1>=0 && p2 >=0 && p1<moveTime.size() && p2<moveTime[0].size() && moveTime[p1][p2] != -1 ){
                        int v= moveTime[p1][p2];
                        if(wt<v){
                            pq.push({v+1,{p1,p2}});
                        }
                        else{
                            pq.push({wt+1,{p1,p2}});
                        }
                    moveTime[p1][p2] = -1;
                }
            }
        }
    }
    return ans;
    }
};