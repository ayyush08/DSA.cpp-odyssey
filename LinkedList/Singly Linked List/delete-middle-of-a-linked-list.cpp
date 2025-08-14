// Delete the middle node in LL

// Given the head of a non-empty singly linked list containing integers, delete the middle node of the linked list. Return the head of the modified linked list.

// The middle node of a linked list of size n is the (⌊n / 2⌋ + 1)th node from the start using 1-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

// Examples:
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5

// Output: head -> 1 -> 2 -> 4 -> 5

// Explanation: n = 5.

// ⌊n / 2⌋ + 1 = 3, therefore middle node has index 3 and so the node with value 3 was deleted.

// Input: head -> 7 -> 6 -> 5 -> 4

// Output: head -> 7 -> 6 -> 4

// Explanation: n = 4.

// ⌊n / 2⌋ + 1 = 3, therefore middle node has index 3 and so the node with value 5 was deleted.

#include <bits/stdc++.h>
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


class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = slow;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = prev->next->next;
        delete slow;
        return head;
    }
};