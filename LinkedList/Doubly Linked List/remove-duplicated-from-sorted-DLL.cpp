// Remove duplicated from sorted DLL
// Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

// Return the head of the modified linked list.

// Examples:
// Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

// Output: head -> 1 <-> 3 <-> 4 <-> 5

// Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

// The underlined nodes were deleted to get the desired result.

// Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

// Output: head -> 1 <-> 2

// Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

// The underlined nodes were deleted to get the desired result.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    ListNode *removeDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *temp = head;
        while (temp && temp->next)
        {
            ListNode *ahead = temp->next;
            while (ahead && ahead->val == temp->val)
            {
                ListNode *duplicate = ahead;
                ahead = ahead->next;
                delete duplicate;
            }

            temp->next = ahead;
            if (ahead)
                ahead->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};