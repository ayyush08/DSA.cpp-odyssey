// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* createNode(int val){
    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    node1->data= val;
    node1->next = NULL;
    return node1;
};
void printNodeCount(struct node *head){
    struct node *temp = head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    printf("Node Count: %d \n",c);
}
void printLinkedList(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        if(temp->next!=NULL){
            printf("-> ");
        }
        temp=temp->next;
    }
    printf("\n");
}

struct node* insertAtBeginning(int val,struct node *head){
    struct node *item = createNode(val);
    item->next=head;
    return item;
    
}
struct node* insertAtEnd(int val,struct node *head){
    struct node *item = createNode(val);
    struct node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=item;
    return head;
    
}
struct node* insertAtPosition(int pos,struct node *head,int val){
    if(head==NULL){
        if(pos==1) return createNode(val);
        return head;
    }
    if(pos==1) return insertAtBeginning(val,head);
    struct node *item = createNode(val);
    struct node *temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos-1) break;
        temp=temp->next;
    }
    item->next=temp->next;
    temp->next=item;
    return head;
    
}

struct node* deleteAtBeginning(struct node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return NULL;
    struct node* newHead = head->next;
    free(head);
    return newHead;
}
struct node* deleteAtEnd(struct node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return NULL;
    struct node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node* lastNode = temp->next;
    temp->next=NULL;
    free(lastNode);
    
    return head;
}
struct node* deleteAtPosition(int pos,struct node *head){
    if(head==NULL|| head->next==NULL){
    }
    if(pos==1) return deleteAtBeginning(head);
    struct node *temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos-1) break;
        temp=temp->next;
    }
    struct node* removalNode = temp->next;
    temp->next=temp->next->next;
    free(removalNode);
    return head;
    
}


int main(){
    struct node *head = createNode(54);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtBeginning(24,head);
    printNodeCount(head);
    // head=insertAtEnd(32,head);
    printLinkedList(head);
    head=insertAtPosition(3,head,5);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtPosition(1,head,45);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtPosition(3,head,65);
    printNodeCount(head);
    printLinkedList(head);
    // head=deleteAtBeginning(head);
    // printNodeCount(head);
    // printLinkedList(head);
    // head=deleteAtEnd(head);
    // printNodeCount(head);
    // printLinkedList(head);
    head=deleteAtPosition(3,head);
    printNodeCount(head);
    printLinkedList(head);
    
}// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* createNode(int val){
    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    node1->data= val;
    node1->next = NULL;
    return node1;
};
void printNodeCount(struct node *head){
    struct node *temp = head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    printf("Node Count: %d \n",c);
}
void printLinkedList(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        if(temp->next!=NULL){
            printf("-> ");
        }
        temp=temp->next;
    }
    printf("\n");
}

struct node* insertAtBeginning(int val,struct node *head){
    struct node *item = createNode(val);
    item->next=head;
    return item;
    
}
struct node* insertAtEnd(int val,struct node *head){
    struct node *item = createNode(val);
    struct node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=item;
    return head;
    
}
struct node* insertAtPosition(int pos,struct node *head,int val){
    if(head==NULL){
        if(pos==1) return createNode(val);
        return head;
    }
    if(pos==1) return insertAtBeginning(val,head);
    struct node *item = createNode(val);
    struct node *temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos-1) break;
        temp=temp->next;
    }
    item->next=temp->next;
    temp->next=item;
    return head;
    
}

struct node* deleteAtBeginning(struct node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return NULL;
    struct node* newHead = head->next;
    free(head);
    return newHead;
}
struct node* deleteAtEnd(struct node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return NULL;
    struct node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node* lastNode = temp->next;
    temp->next=NULL;
    free(lastNode);
    
    return head;
}
struct node* deleteAtPosition(int pos,struct node *head){
    if(head==NULL|| head->next==NULL){
    }
    if(pos==1) return deleteAtBeginning(head);
    struct node *temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos-1) break;
        temp=temp->next;
    }
    struct node* removalNode = temp->next;
    temp->next=temp->next->next;
    free(removalNode);
    return head;
    
}


int main(){
    struct node *head = createNode(54);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtBeginning(24,head);
    printNodeCount(head);
    // head=insertAtEnd(32,head);
    printLinkedList(head);
    head=insertAtPosition(3,head,5);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtPosition(1,head,45);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtPosition(3,head,65);
    printNodeCount(head);
    printLinkedList(head);
    // head=deleteAtBeginning(head);
    // printNodeCount(head);
    // printLinkedList(head);
    // head=deleteAtEnd(head);
    // printNodeCount(head);
    // printLinkedList(head);
    head=deleteAtPosition(3,head);
    printNodeCount(head);
    printLinkedList(head);
    
}// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* createNode(int val){
    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    node1->data= val;
    node1->next = NULL;
    return node1;
};
void printNodeCount(struct node *head){
    struct node *temp = head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    printf("Node Count: %d \n",c);
}
void printLinkedList(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        if(temp->next!=NULL){
            printf("-> ");
        }
        temp=temp->next;
    }
    printf("\n");
}

struct node* insertAtBeginning(int val,struct node *head){
    struct node *item = createNode(val);
    item->next=head;
    return item;
    
}
struct node* insertAtEnd(int val,struct node *head){
    struct node *item = createNode(val);
    struct node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=item;
    return head;
    
}
struct node* insertAtPosition(int pos,struct node *head,int val){
    if(head==NULL){
        if(pos==1) return createNode(val);
        return head;
    }
    if(pos==1) return insertAtBeginning(val,head);
    struct node *item = createNode(val);
    struct node *temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos-1) break;
        temp=temp->next;
    }
    item->next=temp->next;
    temp->next=item;
    return head;
    
}

struct node* deleteAtBeginning(struct node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return NULL;
    struct node* newHead = head->next;
    free(head);
    return newHead;
}
struct node* deleteAtEnd(struct node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return NULL;
    struct node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct node* lastNode = temp->next;
    temp->next=NULL;
    free(lastNode);
    
    return head;
}
struct node* deleteAtPosition(int pos,struct node *head){
    if(head==NULL|| head->next==NULL){
    }
    if(pos==1) return deleteAtBeginning(head);
    struct node *temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos-1) break;
        temp=temp->next;
    }
    struct node* removalNode = temp->next;
    temp->next=temp->next->next;
    free(removalNode);
    return head;
    
}


int main(){
    struct node *head = createNode(54);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtBeginning(24,head);
    printNodeCount(head);
    // head=insertAtEnd(32,head);
    printLinkedList(head);
    head=insertAtPosition(3,head,5);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtPosition(1,head,45);
    printNodeCount(head);
    printLinkedList(head);
    head=insertAtPosition(3,head,65);
    printNodeCount(head);
    printLinkedList(head);
    // head=deleteAtBeginning(head);
    // printNodeCount(head);
    // printLinkedList(head);
    // head=deleteAtEnd(head);
    // printNodeCount(head);
    // printLinkedList(head);
    head=deleteAtPosition(3,head);
    printNodeCount(head);
    printLinkedList(head);
    
}