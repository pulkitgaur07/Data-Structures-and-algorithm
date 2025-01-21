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