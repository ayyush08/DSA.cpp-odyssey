// Rotate a LL
// Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. Do not change the values of the nodes, only change the links between nodes.

// Examples:
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

// Output: head -> 4 -> 5 -> 1 -> 2 -> 3

// Explanation:

// List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

// List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 4

// Output: head -> 2 -> 3 -> 4 -> 5 -> 1

// Explanation:

// List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

// List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

// List after 3 shift to right: head -> 3 -> 4 -> 5 -> 1 -> 2.

// List after 4 shift to right: head -> 2 -> 3 -> 4 -> 5 -> 1.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==NULL) return head;

        for(int i=0;i<k;i++){
            ListNode* temp = head;
            while(temp->next->next) temp = temp->next;

            ListNode* last = temp->next;
            temp->next=NULL;
            last->next = head;
            head=last;
        }
        return head;
    }
    ListNode* rotateRightOptimal(ListNode* head, int k) {
        if(!head || head->next==NULL || k==0) return head;
        int length=1;
        ListNode* temp = head;
        while(temp->next){
            length++;
            temp=temp->next;
        }
        k=k%length;
        temp->next = head;
        int breakPoint = length-k;
        while(breakPoint--) temp = temp->next;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};

//Brute force: O(n*k)
//Optimal: O(n)