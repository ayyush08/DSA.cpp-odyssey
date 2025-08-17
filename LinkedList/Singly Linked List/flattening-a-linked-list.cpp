// Flattening of LL

// Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head
// Each of these child linked lists is in sorted order and connected by a 'child' pointer.

// Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.

// Examples:
// Input:

// Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12

// Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

// Input:

// Output: head -> 2 -> 4 -> 5 -> 10 -> 12 -> 13 -> 16 -> 17 -> 20

// Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

// Constraints:
// n == Number of head nodes
// 1 <= n <= 100
// 1 <= Number of nodes in each child linked list <= 100
// 0 <= ListNode.val <= 1000
// All child linked lists are sorted in non-decreasing order

#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};


class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        while (list1 && list2)
        {
            ListNode *temp = NULL;
            if (list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->child;
            }
            else
            {
                temp = list2;
                list2 = list2->child;
            }
            if (!head)
                head = tail = temp;
            else
            {
                tail->child = temp;
                tail = temp;
            }
        }

        if (list1)
        {
            if (!head)
                head = list1;
            else
                tail->child = list1;
        }
        if (list2)
        {
            if (!head)
                head = list2;
            else
                tail->child = list2;
        }
        return head;
    }
    ListNode *flattenLinkedList(ListNode *&head)
    {
        if (!head || !head->next)
            return head;

        head->next = flattenLinkedList(head->next);

        head = mergeTwoLists(head, head->next);

        return head;
    }
};