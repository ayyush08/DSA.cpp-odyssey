// Add two numbers in LL

// Given two non-empty linked lists l1 and l2 which represent two non-negative integers.

// The digits are stored in reverse order with each node storing one digit.

// Add two numbers and return the sum as a linked list.

// The sum Linked List will be in reverse order as well.
// The Two given Linked Lists represent numbers without any leading zeros, except when the number is zero itself.

// Examples:
// Input: l1 = head -> 5 -> 4, l2 = head -> 4

// Output: head -> 9 -> 4

// Explanation: l1 = 45, l2 = 4.

// l1 + l2 = 45 + 4 = 49.

// Input: l1 = head -> 4 -> 5 -> 6, l2 = head -> 1 -> 2 -> 3

// Output: head -> 5 -> 7 -> 9

// Explanation: l1 = 654, l2 = 321.

// l1 + l2 = 654 + 321 = 975.

// Input: l1 = head -> 1, l2 = head -> 8 -> 7

// Output:
// head -> 9 -> 7

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1;
        ListNode *t2 = l2;

        ListNode *ans = new ListNode();
        ListNode *temp = ans;

        int carry = 0;

        while (t1 || t2 || carry)
        {
            int sum = 0;
            if (t1)
            {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2)
            {
                sum += t2->val;
                t2 = t2->next;
            }
            sum += carry;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }
        return ans->next;
    }
};