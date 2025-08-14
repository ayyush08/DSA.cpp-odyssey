// Find Middle of Linked List
// Given the head of a singly Linked List, return the middle node of the Linked List.

// If the Linked List has an even number of nodes, return the second middle one.

// Examples:
// Input: head -> 3 -> 8 -> 7 -> 1 -> 3

// Output(value at returned node): 7

// Explanation: There are 5 nodes, so the middle node is the 3rd Node, with value 7.

// Input: head -> 2 -> 9 -> 1 -> 4 -> 0 -> 4

// Output(value at returned node): 4

// Explanation: There are 6 nodes, thus both the 3rd and 4th nodes are middle. So the 2nd middle node (4th Node) is returned with value 4.

#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};