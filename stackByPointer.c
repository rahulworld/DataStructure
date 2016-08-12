#include<stdio.h>
#include<malloc.h>
#define max 5
struct stack1
{
    int data;
    struct stack1 *link;
};
struct stack1 *top=NULL;
void push()
{
    struct stack1 *temp;
    temp=(struct stack1*)malloc(sizeof(struct stack1));
    if(top==NULL)
    {
        printf("enter the element \n");
        scanf("%d",&temp->data);
        temp->link=NULL;
        top=temp;
    }
    else
    {
        printf("enter the element \n");
        scanf("%d",&temp->data);
        temp->link=top;
        top=temp;
    }
}
void pop()
{
    int k;
    struct stack1 *temp;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
    else
    {
        temp=top;
        top=temp->link;
        printf("the poped element is %d",temp->data);
    }
}
void display()
{
    struct stack1 *temp;
    temp=top;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d \t",temp->data);
            temp=temp->link;
        }
    }

}
int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
/*
int isFull()
{
    if(a.top==max-1)
        return 1;
    else
        return 0;

}*/
main()
{
    int ch,choice,n=1;
    while(1)
    {
        printf("\n 1. push 2. pop 3. display 4. exit \n enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid Choice");
        }
    }
}
