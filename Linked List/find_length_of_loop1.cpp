// Question : Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

// Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.

// Examples:

// Input: pos = 2,
   
// Output: 4
// Explanation: There exists a loop in the linked list and the length of the loop is 4.
// Input: pos = 3,
   
// Output: 3
// Explanation: The loop is from 19 to 10. So length of loop is 19 → 33 → 10 = 3.
// Input: pos = 0,
    
// Output: 0
// Explanation: There is no loop.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 104
// 0 ≤ pos < number of nodes

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
    int lengthOfLoop(Node *head) {
        unordered_map<Node* , int>vis;
        Node* t = head;
        Node* pre = NULL;
        int num = 1;
        while(t != NULL){
            if(vis[t] < 1){
                vis[t] = num;
            }
            else{
                return vis[pre] - vis[t] + 1;
            }
            num++;
            pre = t;
            t = t->next;
        }
        return 0;
    }
};