#include<bits/stdc++.h>
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
    ListNode *arrayToLinkedList(vector<int> &nums)
    {
        if (nums.empty())
            return NULL;

        ListNode *head = new ListNode(nums[0]);
        ListNode *temp = head;
        for (int i = 1; i < nums.size(); i++)
        {
            ListNode *node = new ListNode(nums[i]);
            temp->next = node;
            node->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};