// 92. Reverse Linked List II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reversal(ListNode *beforeStart, ListNode *afterEnd, ListNode *start, ListNode *end)
    {
        ListNode *curr = start;

        ListNode *prev = beforeStart;
        while (curr != afterEnd)
        {

            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        if (beforeStart)
            beforeStart->next = end;
        start->next = afterEnd;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next || left == right)
            return head;
        ListNode *temp = head;
        ListNode *start = NULL;
        ListNode *end = NULL;
        ListNode *beforeStart = NULL;
        ListNode *afterEnd = NULL;
        int pos = 1;
        while (temp)
        {
            if (!beforeStart)
            {
                if (pos + 1 == left)
                {
                    beforeStart = temp;
                    start = temp->next;
                }
            }
            if (left == 1 && pos == 1)
            {
                start = temp; // starting from head (no beforeSta)
            }
            if (!afterEnd)
            {
                if (pos == right)
                {
                    end = temp;
                    afterEnd = temp->next;
                    break;
                }
            }
            pos++;
            temp = temp->next;
        }
        if (left == 1) // starting from head so after reversal new head will be end
            head = end;
        reversal(beforeStart, afterEnd, start, end);
        return head;
    }
};

// one-pass (earlier too was one-pass but this is more clean)

class Solution2
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;

        for (int i = 1; i < left; i++)
            prev = prev->next;
        ListNode *curr = prev->next;

        for (int i = 0; i < right - left; i++)
        {
            ListNode *nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return dummy->next;
    }
};