// Question : You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

// Examples :

// Input: head = 2 → 6 → 10
// Output: 2 → 5 → 11

// Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
// Input: head = 1 → 15 → 20
// Output: 2 → 13 → 19

// Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
// Constraints:
// 1 <= no. of Nodes <= 104
// 1 <= node.val <= 104

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

class Solution {
    public:
    bool isprime(int val){
        if(val<=1)return 0;
        for(int i=2;i<=val/2;i++){
            if(val%i==0)return 0;
        }
        return 1;
    }
    int near(int val){
        if(isprime(val)){
            return val;
        }
        int l=val-1,r=val+1;
        while(true){
            if(l>=0 &&isprime(l))return l;
            if(isprime(r))return r;
            l--;
            r++;
        }
    }
    Node *primeList(Node *head) {
        Node* tem=head;
        while(tem){
            tem->val=near(tem->val);
            tem=tem->next;
        }
        return head;
    }
};