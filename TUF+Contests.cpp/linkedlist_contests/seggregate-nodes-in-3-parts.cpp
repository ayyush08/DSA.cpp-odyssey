// Segregate Nodes into 3 parts in LL
\
// Given the head of a singly linked list, group all nodes based on the remainder when their indices are divided by 3 (i.e., indices % 3). Rearrange the list so that nodes with the same remainder are grouped together, and the groups appear in the order of increasing remainder values (0, 1, then 2). Return the head of the reordered linked list.

// Consider the 1st node to have index 1 and so on. The relative order of the elements inside each group must remain the same as the given input.

// Examples:
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Output: head -> 3 -> 6 -> 1 -> 4 -> 2 -> 5

// Explanation:

// head -> 1(1) -> 2(2) -> 3(0) -> 4(1) -> 5(2) -> 6(0)

// In brackets, the value of index%3 is given. Ones with the same value are grouped together.

// head -> 3(0) -> 6(0) -> 1(1) -> 4(1) -> 2(2) -> 5(2)

// Input: head -> 6 -> 7 -> 3 -> 3 -> 7 -> 9 -> 1

// Output: head -> 6 -> 3 -> 3 -> 9 -> 7 -> 7 -> 1

// Explanation:

// head -> 6(0) -> 7(1) -> 3(0) -> 3(0) -> 7(1) -> 9(0) -> 1(1)

// In brackets, the value of index%3 is given. Ones with the same value are grouped together.

// // head -> 6(0) -> 3(0) -> 3(0) -> 9(0) -> 7(1) -> 7(1) -> 1(1)

#include<bits/stdc++.h>
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


class Solution {
public:
    ListNode* segregateLinkedList(ListNode* head) {
        ListNode *zeroLL = new ListNode(-1);
        ListNode *oneLL = new ListNode(-1);
        ListNode *twoLL = new ListNode(-1);

        ListNode *zero = zeroLL;
        ListNode *one = oneLL;
        ListNode *two = twoLL;

        ListNode *temp = head;
        int i=0;
        while (temp)
        {
            i++;
            if (i%3 == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (i%3== 1)
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