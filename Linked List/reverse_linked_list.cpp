// Question : 

// Given the head of a linked list, the task is to reverse this list and return the reversed head.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverse(struct Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* reverseList(struct Node* head) {
        return reverse(head);
    }
};