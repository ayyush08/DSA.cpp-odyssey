// Remove bad elements in Linked List

// Given the head of a Linked List and an integer val, remove all nodes having value val and return the head of the modified list.

// Examples:
// Input: head -> 3 -> 4 -> 1 -> 3 -> 5 -> 7, val = 3

// Output: head -> 4 -> 1 -> 5 -> 7

// Explanation: The nodes with value 3 were removed.

// Input: head -> 1 -> 2 -> 4 -> 5 -> 3 -> 7, val = 7

// Output: head -> 1 -> 2 -> 4 -> 5 -> 3

// Explanation: The node with value 7 was removed.

// Constraints:
// 1 <= Number of nodes in the Linked List <= 105
// -104 <= ListNode.val <= 104
// -104 <= val <= 104

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
    ListNode *removeBadElements(ListNode *head, int val)
    {

        while (head && head->val == val)
        {
            ListNode *toDel = head;
            head = head->next;
            delete toDel;
        }
        if (!head)
            return NULL;
        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp)
        {
            if (temp->val == val)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};