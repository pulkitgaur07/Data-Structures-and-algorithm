// Question : 

// Given a head of the singly linked list. If a loop is present in the list then return the first node of the loop else return NULL.

// Custom Input format:
// A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

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
    Node* findFirstNode(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* curr= head;
        while(curr!=NULL){
            if(mp.find(curr->next)!= mp.end()){
                return curr->next;
            }
            mp[curr]= curr->next;
            curr= curr->next;
            
        }
        return NULL;
    }
};