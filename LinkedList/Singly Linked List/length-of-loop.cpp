// Length of loop in LL

// Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.

// A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.

// Note that pos is not passed as a parameter.

// Examples:

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

// Output: 4

// Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

// Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

// Output: 0

// Explanation: No loop is present in the linked list.

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
    int findLength(ListNode *slow, ListNode *fast)
    {
        int len = 1;
        slow = slow->next;
        while (slow != fast)
        {
            len++;
            slow = slow->next;
        }
        return len;
    }
    int findLengthOfLoop(ListNode *head)
    {
        if (!head || !head->next)
            return 0;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return findLength(slow, fast);
            }
        }
        return 0;
    }
};