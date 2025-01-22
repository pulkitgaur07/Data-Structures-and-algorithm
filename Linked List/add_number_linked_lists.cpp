#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    struct Node* reverse(struct Node* head){
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
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2){
        Node* head1 = reverse(num1);
        Node* head2 = reverse(num2);
        int rem = 0;
        Node* temp = new Node(-1);
        Node* head = temp;
        while(head1 || head2 || rem){
            int d1 = 0,d2 = 0;
            if(head1) {d1 = head1->data; head1 = head1->next;}
            if(head2) {d2 = head2->data; head2 = head2->next;}
            int val = rem + d1 + d2;
            Node* newNode = new Node(val%10);
            rem = val/10;
            temp -> next = newNode;
            temp = temp -> next;
        }
        head = head->next;
        head = reverse(head);
        temp = head;
        while(temp && temp->data==0){
            temp = temp->next;
        }
        if(!temp) return new Node(0);
        head = temp;
        return head;
    }
};
