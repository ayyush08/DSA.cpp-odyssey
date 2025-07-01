// ou are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
};