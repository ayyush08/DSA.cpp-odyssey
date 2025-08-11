#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
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
    ListNode *deleteHead(ListNode *&head)
    {
        if (head == NULL)
            return NULL;

        ListNode *temp = head;
        temp = temp->next;
        head->next == NULL;
        return temp;
    }
    ListNode *deleteTail(ListNode *&head)
    {
        if (head == nullptr || head->next == NULL)
            return nullptr;

        ListNode *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
    ListNode *deleteKthNode(ListNode *&head, int k)
    {
        if (!head)
            return NULL;
        ListNode *temp = head;
        if (k == 1)
        {
            head = head->next;
            delete temp;
            return head;
        }
        int cnt = 0;

        while (temp)
        {
            cnt++;
            if (cnt == k - 1)
                break;
            temp = temp->next;
        }
        if (temp->next->next)
        {
            ListNode *ahead = temp->next;
            temp->next = temp->next->next;
            ahead->next = nullptr;
        }
        else
        {
            temp->next = NULL;
        }
        return head;
    }
    ListNode *deleteNodeWithValueX(ListNode *&head, int X)
    {
        if (head == NULL)
            return NULL;
        ListNode *temp = head;
        if (head->val == X)
        {
            if (head->next == NULL)
                return NULL;
            head = head->next;
            delete temp;
            return head;
        }
        while (temp->next)
        {
            if (temp->next->val == X)
                break;
            temp = temp->next;
        }
        if (!temp)
            return head;

        ListNode *ahead = temp->next ? temp->next : NULL;
        if (ahead && ahead->next)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp->next = NULL;
        }
        delete ahead;
        return head;
    }
};