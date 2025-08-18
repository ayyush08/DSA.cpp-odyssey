// Delete all occurrences of a key in DLL

// Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

// Examples:
// Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

// Output: head -> 2 <-> 3 <-> 4

// Explanation: All nodes with the value 1 were removed.

// Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

// Output: head -> 3 <-> -1 <-> 4

// Explanation: All nodes with the value 2 were removed.

// Note that the value of head is changed.

// Input: head -> 7 <-> 7 <-> 7 <-> 7, target = 7

// Output:
// head
// Constraints:
// 0 <= number of nodes in the linked list <= 105
// -104 <= ListNode.val <= 104
// -104 <= target <= 104

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
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {
        if (!head)
            return NULL;
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val == target)
            {
                ListNode *front = temp->next;
                ListNode *back = temp->prev;
                if (!back)
                {
                    head = front;
                    if (front)
                        front->prev = NULL;
                }
                else
                {
                    back->next = front;
                    if (front)
                        front->prev = back;
                }
                delete temp;
                temp = front;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};