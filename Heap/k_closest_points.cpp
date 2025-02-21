#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> kClosestPoints(vector<int>& points, int k,int x) {
        priority_queue<pair<int,int>>pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            pq.push({abs(points[i]-x),points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};