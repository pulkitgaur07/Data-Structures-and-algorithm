// Question : Given a sorted circular linked list, the task is to insert a new node in this circular linked list so that it remains a sorted circular linked list.

// Examples:

// Input: head = 1->2->4, data = 2
// Output: 1->2->2->4
// Explanation: We can add 2 after the second node.

// Input: head = 1->4->7->9, data = 5
// Output: 1->4->5->7->9
// Explanation: We can add 5 after the second node.

// Constraints:
// 2 <= number of nodes <= 106
// 0 <= node->data <= 106
// 0 <= data <= 106

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        if(head->data>data){
            Node* curr=head;
            while(curr->next!=head){
                curr=curr->next;
            }
            Node* newnode=new Node(data);
            curr->next=newnode;
            newnode->next=head;
            return newnode;
        }
        Node* curr=head;
        Node* prev=head;
        while(curr->data<=data){
            prev=curr;
            curr=curr->next;
            if(curr==head){
                break;
            }
        }
        Node* newnode=new Node(data);
        prev->next=newnode;
        newnode->next=curr;
        return head;
    }
};