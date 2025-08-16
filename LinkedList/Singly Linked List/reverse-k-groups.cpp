// Reverse LL in group of given size K
// Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.

// Do not change the values of the nodes, only change the links between nodes.

// Examples:
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

// Output: head -> 2 -> 1 -> 4 -> 3 -> 5

// Explanation: The groups 1 -> 2 and 3 -> 4 were reversed as 2 -> 1 and 4 -> 3.

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 3

// Output: head -> 3 -> 2 -> 1 -> 4 -> 5

// Explanation: The groups 1 -> 2 -> 3 were reversed as 3 -> 2 -> 1.

// Note that 4 -> 5 was not reversed.

// Input: head -> 6 -> 1 -> 2 -> 3 -> 4 -> 7, k = 4

// Output:
// head -> 3 -> 2 -> 1 -> 6 -> 4 -> 7
// Constraints:
// 1 <= k <= number of nodes in the linked list <= 105
// -104 <= ListNode.val <= 104


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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp,int k){
        k--;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;;
        ListNode* recent = NULL;

        while(temp){
            ListNode* kThNode = getKthNode(temp,k);

            if(!kThNode){
                if(recent) recent->next = temp;
                break;
            }

            ListNode* ahead = kThNode->next;

            kThNode->next = NULL;

            reverseList(temp);

            if(temp==head) head = kThNode;
            else{
                recent->next = kThNode;
            }

            recent = temp;
            temp=ahead;

        }
        return head;
    }
};