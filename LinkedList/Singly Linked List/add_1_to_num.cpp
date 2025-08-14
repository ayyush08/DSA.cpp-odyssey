// Add one to a number represented by LL
// 100 points


// 0

// Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.



// The number will contain no leading zeroes except when the value represented is zero itself.
#include <bits/stdc++.h>
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
    //Iterative
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
    ListNode *addOne(ListNode *head) {
        head = reverseList(head);
        ListNode* temp = head;
        int carry=1;
        while(temp!=NULL){
            int sum = temp->val+carry;
            carry=sum/10;
            temp->val=sum%10;
            if(carry==0) break;
            if(temp->next==NULL && carry!=0){
                temp->next=new ListNode(carry);
                break;
            }
            temp=temp->next;
        }
        head=reverseList(head);
        return head;
    }
    //Recursive
    int addHelper(ListNode* temp){ 
        if(temp==NULL) return 1;

        int carry=addHelper(temp->next);
        temp->val+=carry;
        if(temp->val<10) return 0;
        temp->val=0;
        return 1;
    }
    ListNode *addOne(ListNode *head) {
        int carry = addHelper(head);
        if(carry==1){
            ListNode* newHead = new ListNode(1);
            newHead->next=head;
            return newHead;
        }
        return head;
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
    head = sol.addOne(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
