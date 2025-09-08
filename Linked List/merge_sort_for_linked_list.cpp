// Question : You are given the head of a linked list. You have to sort the given linked list using Merge Sort.

// Examples:

// Input:
    
// Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60
// Explanation: After sorting the given linked list, the resultant list will be:
    
// Input:
    
// Output: 2 -> 5 -> 8 -> 9
// Explanation: After sorting the given linked list, the resultant list will be:
    
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 0 ≤ node->data ≤ 106\

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
    Node* merge(Node* head1, Node* head2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while (head1 && head2) {
            int val1 = head1->data, val2 = head2->data;
            if (val1 > val2) {
                temp->next = head2;
                head2 = head2->next;
            } else {
                temp->next = head1;
                head1 = head1->next;
            }
            temp = temp->next;
        }
        if (head1) temp->next = head1;
        else if (head2) temp->next = head2;
        return dummy->next;
    }
  
    Node* secondHead(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
  
    Node* merge_sort(Node* head) {
        if (!head) return head;
        if (head->next == NULL) return head;
        Node* start = head;
        Node* temp = secondHead(head);
        Node* middle = temp->next;
        temp->next = NULL;
        Node* head1 = merge_sort(start);
        Node* head2 = merge_sort(middle);
        return merge(head1, head2);
    }
    Node* mergeSort(Node* head) {
        return merge_sort(head);
    }
};