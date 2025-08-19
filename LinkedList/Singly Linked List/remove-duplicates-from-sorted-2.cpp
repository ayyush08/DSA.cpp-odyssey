// 82. Remove Duplicates from Sorted List II

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *start = head; //track starting non-duplicate
        ListNode *end = head; //track end of duplicates
        ListNode *prev = NULL; //track previous non-duplicate
        int dups = 0;
        while (end)
        {
            while (end && end->val == start->val) // Find end of duplicates
            {
                end = end->next;
                dups++;
            }

            if (dups == 1) // If no duplicates found i.e., unique element at start
                prev = start;

            if (dups > 1) // If duplicates found
            {
                ListNode *temp = start;
                while (temp != end) //delete all duplicates
                {
                    ListNode *dup = temp;
                    temp = temp->next;
                    delete dup;
                }

                if (!prev) // If no non-duplicate found before means head is duplicate so update head to next non-duplicate
                    head = end;
                else
                    prev->next = end; // Link previous non-duplicate to next non-duplicate
            }
            start = end; //go to next non-duplicate
            dups = 0; //reset dup count
        }
        return head;
    }
};