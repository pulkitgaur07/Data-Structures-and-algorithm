// Question : Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    void putData(Node* r, vector<int> &v) {
        if (!r)
            return;
        v.push_back(r->data);
        putData(r->next, v);
        return;
    }
    
    Node* convertAtoL(int i, int n, vector<int> &arr) {
        if (i == n)
            return NULL;
        Node* temp = new Node(arr[i]);
        temp->next = convertAtoL(i + 1, n, arr);
        return temp;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        vector<int> allData;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            putData(arr[i], allData);
        }
        sort(allData.begin(), allData.end());
        int nn = allData.size();
        return convertAtoL(0, nn, allData); 
    }
};