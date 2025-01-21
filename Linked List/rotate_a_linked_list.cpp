#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
    Node* rotate(Node* head, int k) {
        if(!head) return head;
        int len = 0;
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            len++;
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        k = k%len;
        int cnt = 0;
        while(cnt != k){
            head = head->next;
            prev = prev->next;
            cnt++;
        }
        prev->next = NULL;
        return head;
    }
};