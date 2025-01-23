// Question : 

// Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseKGroup(Node *head, int k) {
        if(!head) return NULL;
        int cnt = 0;
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head;
        while(curr && cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};