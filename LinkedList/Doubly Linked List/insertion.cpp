#include <bits/stdc++.h>
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
    ListNode *insertBeforeHead(ListNode *head, int X)
    {
        if (!head)
            return new ListNode(X);

        ListNode *node = new ListNode(X);
        node->next = head;
        head->prev = node;
        return node;
    }
    ListNode *insertBeforeTail(ListNode *head, int X)
    {
        ListNode *node = new ListNode(X);
        if (!head)
            return node;
        if (!head->next)
        {
            node->next = head;
            head->prev = node;
            return node;
        }
        ListNode *temp = head;
        while (temp->next)
            temp = temp->next;
        ListNode *behind = temp->prev;
        behind->next = node;
        node->next = temp;
        node->prev = behind;
        temp->prev = node;
        return head;
    }
    ListNode *insertBeforeKthPosition(ListNode *head, int X, int K)
    {
        ListNode *node = new ListNode(X);
        if (!head)
            return node;
        if (!head->next || K == 1)
            return insertBeforeHead(head, X);
        ListNode *temp = head;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            if (cnt == K)
                break;
            temp = temp->next;
        }
        ListNode *behind = temp->prev;
        ListNode *ahead = temp->next;
        if (!ahead)
            return insertBeforeTail(head, X);
        behind->next = node;
        node->prev = behind;
        node->next = temp;
        temp->prev = node;
        return head;
    }
    void insertBeforeGivenNode(ListNode *node, int X)
    {
        ListNode *newNode = new ListNode(X);
        ListNode *behind = node->prev;
        behind->next = newNode;
        newNode->next = node;
        node->prev = newNode;
        newNode->prev = behind;
    }
};