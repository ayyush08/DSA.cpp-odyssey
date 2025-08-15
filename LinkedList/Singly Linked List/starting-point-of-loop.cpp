// Find the starting point in LL

// Given the head of a singly linked list, the task is to find the starting point of a loop in the linked list if it exists. Return the starting node if a loop exists; otherwise, return null.

// A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos denotes the index (0-based) of the node from where the loop starts.

// Note that pos is not passed as a parameter.

// Examples:

// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

// Output(value of the returned node is displayed): 2

// Expla﻿nation: The tail of the linked list connects to the node at 1st index.

// Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

// Output(value of the returned node is displayed): null

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
    ListNode *findStartingPoint(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};