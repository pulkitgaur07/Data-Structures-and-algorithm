// Question : Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

// There are two cases for median on the basis of data set size.

// 1. If the data set has an odd number then the middle one will be consider as median.
// 2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();
        vector<double> ans;
        int cntEle = 1;
        maxHeap.push(arr[0]);
        ans.push_back((double)(arr[0]));
        for(int i = 1; i < n; ++i) {
            int top = maxHeap.top();
            if(top < arr[i]) {
                minHeap.push(arr[i]);
                if(minHeap.size() > maxHeap.size()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            } else {
                maxHeap.push(arr[i]);
                if(maxHeap.size() > minHeap.size() + 1) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
            ++cntEle;
            if(cntEle & 1) {
                ans.push_back((double)(maxHeap.top()));
            } else {
                double temp = (minHeap.top() + maxHeap.top()) / 2.0;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};