// Question : Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

// Examples:

// Input:
   
// Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
// Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
// 1st list: 1 -> 3 -> 7
// 2nd list: 2 -> 4 -> 8
// 3rd list: 9
// The merged list will be: 
    
// Input:
   
// Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
// Explanation: The arr[] has 3 sorted linked list of size 2, 1, 3.
// 1st list: 1 -> 3
// 2nd list: 8
// 3rd list: 4 -> 5 -> 6
// The merged list will be: 
    
// Constraints
// 1 ≤ total no. of nodes ≤ 105
// 1 ≤ node->data ≤ 103

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = 3001;
        int freq[n] = {0};
        for (auto &node: arr){
            Node* curr = node;
            while (curr!=NULL){
                freq[curr->data]++;
                curr=curr->next;
            }
        }
        Node* currNode = new Node(0);
        Node* head = currNode;
        for (int i=0; i<n; i++){
            while (freq[i] != 0){
                Node* newNode = new Node(i);
                currNode->next = newNode;
                currNode = newNode;
                freq[i]--;
            }
        }
        return head->next;
    }
};