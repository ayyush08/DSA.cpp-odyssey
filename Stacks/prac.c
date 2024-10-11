#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack
{
    int top;
    int arr[MAX];
};
void initStack(struct stack *st)
{
    st->top=-1;
}
int isEmpty(struct stack *st)
{
    return (st->top==-1);
}
int isFull(struct stack *st)
{
    return (st->top==MAX-1);
}
int push(struct stack *st, int item)
{
    if(isFull(st))
    {
        printf("Stack Overflow\n");
        return -1;
    }
    return st->arr[++st->top]=item;
}
int pop(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->arr[st->top--];
}
int peek(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->arr[st->top];
}
int main()
{
    // int size;
    // struct stack st;
    // initStack(&st);
    // printf("Enter the size of the array: ");
    // scanf("%d",&size);
    // int arr[size];
    // int nge[size];
    // printf("Enter the elements of the array: ");
    // for(int i=0;i<size;i++)
    // {
    //     scanf("%d",&arr[i]);
    //     nge[i]=-1;
    // }
    // printf("The elements of the array in next greater element order are: ");
    // for(int i=size-1;i>=0;i--){
    //     while(!isEmpty(&st)&&peek(&st)<=arr[i])
    //     {
    //         pop(&st);
    //     }
    //     if(isEmpty(&st)) nge[i]=-1;
    //     else nge[i]=peek(&st);
    //     push(&st,arr[i]);
    // }
    // for(int i=0;i<size;i++)
    // {
    //     printf("%d ",nge[i]);
    // }
    int size;
    struct stack st;
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