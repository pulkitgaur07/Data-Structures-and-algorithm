// Question : There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 7

// Explanation:

// The minimum time required is 7 seconds.

// At time t == 4, move from room (0, 0) to room (1, 0) in one second.
// At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
// Example 2:

// Input: moveTime = [[0,0,0,0],[0,0,0,0]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

// At time t == 0, move from room (0, 0) to room (1, 0) in one second.
// At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
// At time t == 3, move from room (1, 1) to room (1, 2) in one second.
// At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 4

// Constraints:

// 2 <= n == moveTime.length <= 750
// 2 <= m == moveTime[i].length <= 750
// 0 <= moveTime[i][j] <= 109

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>> >,greater<pair<int,pair<int,pair<int,int>>>>>pq;
        pq.push(make_pair(0,make_pair(1,make_pair(0,0))));
        int row[4] = {-1,0,1,0};
        int col[4] = {0,-1,0,1};

        int n = moveTime.size();
        int m = moveTime[0].size();
        int ans =INT_MAX;
        vector<vector<int> >visi(n,vector<int>(m,0));
        while(pq.size()>0){
            int size = pq.size();

            for(int i =0;i<size;i++){
                auto frnt = pq.top();
                pq.pop();
                    int time = frnt.first;
                int add = frnt.second.first;
                    int x = frnt.second.second.first;
                    int y = frnt.second.second.second;

                    if(x == n-1 && y == m-1){
                    ans = min(ans,time);
                    }
                    for(int i =0;i<4;i++){
                    int p1 = x + row[i];
                    int p2 = y + col[i];
                    if(p1>=0 && p2>=0 &&  p1<n && p2< m && moveTime[p1][p2]<= time && visi[p1][p2] == 0){
                        int t =0;
                        if(add == 1){
                            t = 2;
                        }
                        else{
                            t = 1;
                        }
                                visi[p1][p2] = 1;
                        pq.push(make_pair(time+add,make_pair(t,make_pair(p1,p2))));

                    }
                    else if(p1>=0 && p2>=0 &&  p1<n && p2< m && moveTime[p1][p2]> time && visi[p1][p2] == 0){
                        int t =0;
                        if(add == 1){
                            t = 2;
                        }
                        else{
                            t = 1;
                        }
                        visi[p1][p2] = 1;
                        pq.push(make_pair(moveTime[p1][p2]+add,make_pair(t,make_pair(p1,p2))));
                    }
                    }
            }
        }
        if(ans>=INT_MAX){
            return -1;
        }
        return ans;
    }
};