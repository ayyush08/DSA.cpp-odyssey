// Special Linked List

// Given the head of Linked List and an integer val, partition the list as a special Linked List.
// A special linked list is one in which all nodes with values less than val come before all nodes equal to or greater than val. You have to keep the relative ordering of the nodes within the partition the same as the initial list.

// Examples:
// Input: head -> 5 -> 2 -> 4 -> 1 -> 3 -> 4, val = 3

// Output: head -> 2 -> 1 -> 5 -> 4 -> 3 -> 4

// Explanation: head -> 5 -> 2 -> 4 -> 1 -> 3 -> 4

// The underlined nodes are less than val, so they come before others.

// Note that the ordering of elements within the group is maintained.

// Input: head -> 3 -> 7 -> 2 -> 5 -> 3 -> 1, val = 4

// Output: head -> 3 -> 2 -> 3 -> 1 -> 7 -> 5

// Explanation: head -> 3 -> 7 -> 2 -> 5 -> 3 -> 1

// Constraints:
// 1 <= Number of Nodes in the Linked List <= 105
// -104 <= ListNode.val <= 104
// -104 <= val <= 104﻿

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
    ListNode *partitionList(ListNode *head, int val)
    {
        if (!head)
            return NULL;

        ListNode *leftHead = NULL;
        ListNode *rightHead = NULL;

        ListNode *left = leftHead;
        ListNode *right = rightHead;

        ListNode *temp = head;

        while (temp)
        {
            ListNode *nextNode = temp->next;
            temp->next = NULL;
            if (temp->val < val)
            {
                if (!leftHead)
                    leftHead = left = temp;
                else
                {
                    left->next = temp;
                    left = left->next;
                }
            }
            else
            {
                if (!rightHead)
                    rightHead = right = temp;
                else
                {
                    right->next = temp;
                    right = right->next;
                }
            }
            temp = nextNode;
        }
        if (leftHead)
        {
            left->next = rightHead;
            return leftHead;
        }
        else
            return rightHead;
    }
};