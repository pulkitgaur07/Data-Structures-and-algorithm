// Question : Given the head of a singly linked list and an integer k. Swap the kth node (1-based index) from the beginning and the kth node from the end of the linked list. Return the head of the final formed list and if it's not possible to swap the nodes return the original list.

// Examples:

// Input: k = 1,
  
// Output: 5 -> 2 -> 3 -> 4 -> 1
// Explanation: Here k = 1, hence after swapping the 1st node from the beginning and end the new list will be 5 -> 2 -> 3 -> 4 -> 1.
  
// Input: k = 2,
  
// Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
// Explanation: Here k = 2, hence after swapping the 2nd node from the beginning and end the new list will be 5 -> 9 -> 8 -> 5 -> 10 -> 3.
  
// Constraints:
// 1 ≤ list size ≤ 104
// 1 ≤ node->data ≤ 106
// 1 ≤ k ≤ 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        Node * temp = head;
        int count = 1;
        while(temp->next!= NULL){ count++; temp = temp->next;}
        if(count<k) return head;
        temp = head;
        for(int i=1; i<k; i++) temp = temp->next;
        Node * a = head;
        for(int i=1; i < count-k+1; i++) a = a->next;
        swap(a->data, temp->data);
        return head;
    }
};