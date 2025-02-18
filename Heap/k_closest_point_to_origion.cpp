// Question : Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance, defined as: 
// sqrt( (x2 - x1)2 + (y2 - y1)2 )

// Note: You can return the k closest points in any order, driver code will sort them before printing.


#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            pq.push({d,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};