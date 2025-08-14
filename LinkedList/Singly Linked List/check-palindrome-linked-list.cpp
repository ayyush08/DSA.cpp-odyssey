// Check if LL is palindrome or not

// Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false.

// A palindrome is a sequence that reads the same forward and backwards.

// Examples:
// Input: head -> 3 -> 7 -> 5 -> 7 -> 3

// Output: true

// Explanation: 37573 is a palindrome.

// Input: head -> 1 -> 1 -> 2 -> 1

// Output: false

// Explanation: 1121 is not a palindrome.

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secHalf = reverseList(slow);
        ListNode *left = head;
        ListNode *ryt = secHalf;

        while (ryt)
        {
            if (ryt->val != left->val)
                return false;
            ryt = ryt->next;
            left = left->next;
        }
        reverseList(secHalf->next);
        return true;
    }
};