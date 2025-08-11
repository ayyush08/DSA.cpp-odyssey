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
    ListNode *insertAtHead(ListNode *&head, int X)
    {
        ListNode *node = new ListNode(X);
        if (!head)
            return node;

        node->next = head;
        return node;
    }
    ListNode* insertAtTail(ListNode* &head, int X) {
        ListNode* node = new ListNode(X);
        if(!head) return node;

        ListNode* temp = head;

        while(temp->next){
            temp=temp->next;
        }
        temp->next = node;
        return head;
    }
    ListNode* insertAtKthPosition(ListNode* &head, int X, int k) {
        if(head==NULL){
            if(k==1) return new ListNode(X);
            return head;
        }
        if(k==1) return new ListNode(X,head);
        int cnt = 0;
        ListNode* temp = head;
        while(temp)
        {
            cnt++;
            if(cnt==k-1){
                ListNode* node = new ListNode(X,temp->next);
                temp->next = node;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        if(head==NULL){
            return head;
        }
        if(head->val == X) return new ListNode(val,head);
        ListNode* temp = head;
        while(temp->next){
            if(temp->next->val == X){
                ListNode* node = new ListNode(val,temp->next);
                temp->next = node;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};