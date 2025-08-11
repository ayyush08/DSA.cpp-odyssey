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
    ListNode *deleteHead(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *lead = head;
        head = head->next;
        head->prev = NULL;

        delete lead;
        return head;
    }
    ListNode* deleteTail(ListNode* head) {
        if(!head || !head->next) return NULL;
        
        ListNode* tail = head;
        while(tail->next) tail=tail->next;
        ListNode* behind = tail->prev;
        behind->next =  NULL;
        tail->prev = NULL;
        delete tail;
        return head;
    }
    ListNode* deleteKthElement(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            cnt++;
            if(cnt==k) break;
            temp=temp->next;
        }
        ListNode* behind = temp->prev;
        ListNode* ahead = temp->next;
        if(!behind && !ahead){
            delete head;
            return NULL;
        }else if(!behind) return deleteHead(head);
        else if(!ahead) return deleteTail(head);
        else{
            behind->next = temp->next;
            ahead->prev = temp->prev;
            temp->next = temp->prev = NULL;
            delete temp;
            return head;
        }
        return head;
    }
    void deleteGivenNode(ListNode* node) {
        ListNode* behind = node->prev;
        ListNode* ahead = node->next;
        if(!ahead){
            behind->next=NULL;
            node->prev=NULL;
            delete node;
            return;
        }
            behind->next=node->next;
            ahead->prev=node->prev;
            node->next=node->prev=NULL;
            delete node;

    }
};