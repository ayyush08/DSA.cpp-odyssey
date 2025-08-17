// Sort LL

// Given the head of a singly linked list. Sort the values of the linked list in non-decreasing order and return the head of the modified linked list.

// Examples:
// Input: head -> 5 -> 6 -> 1 -> 2 -> 1

// Output: head -> 1 -> 1 -> 2 -> 5 -> 6

// Explanation: 1 <= 1 <= 2 <= 5 <= 6

// Input: head -> 6 -> 5 -> -1 -> -2 -> -3

// Output: head -> -3 -> -2 -> -1 -> 5 -> 6

// Explanation: -3 <= -2 <= -1 <= 5 <= 6

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
                list1 = list1->next;
            }
            else
            {
                temp = list2;
                list2 = list2->next;
            }
            if (!head)
                head = tail = temp;
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        if (list1)
        {
            if (!head)
                head = list1;
            else
                tail->next = list1;
        }
        if (list2)
        {
            if (!head)
                head = list2;
            else
                tail->next = list2;
        }
        return head;
    }
    ListNode *middleOfLinkedList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *partition = middleOfLinkedList(head);

        ListNode *right = partition->next;
        ListNode *left = head;
        partition->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};
