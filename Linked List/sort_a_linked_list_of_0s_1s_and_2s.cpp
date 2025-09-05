// Question : Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

// Examples:

// Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
   
// Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
// Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:
   
// Input: head = 2 → 2 → 0 → 1
   
// Output: 0 → 1 → 2 → 2
// Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
   
// Constraints:
// 1 ≤ no. of nodes ≤ 106
// 0 ≤ node->data ≤ 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        if(head==NULL) return head;
        Node* curr=head;
        int cntZero=0,cntOne=0,cntTwo=0;
        
        while(curr!=NULL){
            if(curr->data==0) cntZero++;
            if(curr->data==1) cntOne++;
            curr=curr->next;
        }
        
        curr=head;
        while(curr){
            if(cntZero>0) {
                curr->data=0;
                cntZero--;
                }
            else if(cntOne>0){
                curr->data=1;
                cntOne--;
            }
            else{
                curr->data=2;
            }
            curr=curr->next;
        }
        return head;
    }
};