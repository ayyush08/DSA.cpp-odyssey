#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list:
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
    ListNode* reverseListRecursive(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* nextNode = reverseList(head->next);

        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;
        return nextNode;
    }
};


void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    cout << "Original Linked List: ";
    printLinkedList(head);
    Solution sol;
    // head = sol.reverseList(head);
    head = sol.reverseListRecursive(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
