// Sort a LL of 0's 1's and 2's

// Given the head of a singly linked list consisting of only 0, 1 or 2. Sort the given linked list and return the head of the modified list. Do it in-place by changing the links between the nodes without creating new nodes.

// Examples:
// Input: head -> 1 -> 0 -> 2 -> 0 -> 1

// Output: head -> 0 -> 0 -> 1 -> 1 -> 2

// Explanation: The values after sorting are [0, 0, 1, 1, 2].

// Input: head -> 1 -> 1 -> 1 -> 0

// Output: head -> 0 -> 1 -> 1 -> 1

// Explanation: The values after sorting are [0, 1, 1, 1].

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
    ListNode *sortList(ListNode *head)
    {
        ListNode *zeroLL = new ListNode(-1);
        ListNode *oneLL = new ListNode(-1);
        ListNode *twoLL = new ListNode(-1);

        ListNode *zero = zeroLL;
        ListNode *one = oneLL;
        ListNode *two = twoLL;

        ListNode *temp = head;

        while (temp)
        {
            if (temp->val == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->val == 1)
            {
                one->next = temp;
                one = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }

        zero->next = oneLL->next ? oneLL->next : twoLL->next;
        one->next = twoLL->next;
        two->next = NULL;

        ListNode *ans = zeroLL->next;
        delete zeroLL;
        delete oneLL;
        delete twoLL;
        return ans;
    }
};