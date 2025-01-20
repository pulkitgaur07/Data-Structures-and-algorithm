#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* head = NULL;
        if(head1->data < head2->data){
            head = head1;
        }
        else{
            head = head2;
        }
        Node* temp = NULL;
        while(head1 && head2){
            if(head1->data < head2->data){
                if(!temp) temp = head1;
                else{
                    temp->next = head1;
                    temp = head1;
                }
                head1 = head1->next;
            }
            else{
                if(!temp) temp = head2;
                else{
                    temp->next = head2;
                    temp = head2;
                }
                head2 = head2->next;
            }
        }
        if(head1) temp->next = head1;
        if(head2) temp->next = head2;
        return head;
    }
};