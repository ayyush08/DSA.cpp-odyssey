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
void addNodeAtBeginning(struct node* header,int val){
    struct node* node1 = createNode(val);
    node1->next = header->next;
    header->next=node1;
    header->data+=1;
}
void addNodeAtEnd(struct node* header,int val){
    struct node* temp = header->next;
    while(temp->next!=NULL) temp = temp->next;
    struct node* node1 = createNode(val);
    temp->next=node1;
    node1->next = NULL;
    header->data+=1;
}
void addNodeAtPosition(struct node* header,int val,int pos){
    struct node* temp = header->next;
    int c=0;
    while(temp!=NULL){
    c++;
    if(c==pos-1) break;
    temp = temp->next;
    }
    struct node* node1 = createNode(val);
    node1->next = temp->next;
    temp->next=node1;
    header->data+=1;
}

void deleteNodeAtBeginning(struct node* header){
    struct node* node1 = header->next;
    header->next = header->next->next;
    delete(node1);
    header->data-=1;
}
void deleteNodeAtEnd(struct node* header){
    if(header->next->next==NULL){
        header->next=NULL;
    }
    struct node* temp = header->next;
    while(temp->next->next!=NULL) temp = temp->next;
    struct node* curr = temp->next;
    temp->next=NULL;
    delete(curr);
    header->data-=1;
}
void deleteNodeAtPosition(struct node* header,int pos){
    struct node* temp = header->next;
    int c=0;
    while(temp->next!=NULL){
        c++;
        if(c==pos-1) break;
        temp = temp->next;
    } 
    struct node* curr = temp->next;
    // curr->next=NULL;
    temp->next=curr->next;
    delete(curr);
    header->data-=1;
}

int main(){
    // struct node* header = (struct node*)malloc(sizeof(struct node));
    struct node* header = createNode(0);
    // printf("%d %d",header->data,header->next);
    addNodeAtBeginning(header,4);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    addNodeAtBeginning(header,5);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    addNodeAtEnd(header,6);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    addNodeAtEnd(header,8);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    addNodeAtPosition(header,18,3);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    deleteNodeAtBeginning(header);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    deleteNodeAtEnd(header);
    printf("The number of nodes are %d\n" ,header->data);
    printLinkedList(header->next);
    // deleteNodeAtPosition(header,2);
    // printf("The number of nodes are %d\n" ,header->data);
    // printLinkedList(header->next);
}

// struct Node* mergeLists(struct Node* list1, struct Node* list2) {
//     //Type your code here
//     Node* temp1 = list1->next;
//     Node* temp2 = list2->next;
//     Node* alt1;
//     Node* alt2;
//     while(temp1!=NULL && temp2!=NULL){
//         alt1=temp1->next;
//         alt2=temp2->next;
//         temp1->next=temp2;
//         if(alt1==NULL) break;
//         temp2->next=alt1;
//         temp1=alt1;
//         temp2=alt2;
//         list1->data+=1;
//     }
//     return list1;
// }