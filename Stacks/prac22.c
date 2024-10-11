#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Node *createNode(int data)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void initStack(struct Stack *st)
{
    st->top=NULL;
}

int isEmpty(struct Stack *st)
{
    return (st->top==NULL);
}

void push(struct Stack *st, int val){
    struct Node *newNode=createNode(val);
    newNode->next=st->top;
    st->top=newNode;
}


int pop(struct Stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp=st->top;
    st->top=st->top->next;
    int val=temp->data;
    free(temp);
    return val;
}


int peek(struct Stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->top->data;
}

int main()
{
    int size;
    struct Stack st;
    initStack(&st);
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter book order ids: ");
    for(int i=0;i<size;i++)
    {
        int id;
        scanf("%d",&id);
        push(&st,id);
    }
    printf("Top element is: %d\n",peek(&st));
    printf("Stack elements are: ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",pop(&st));
    }
return 0;
}