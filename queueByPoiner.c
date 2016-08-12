#include<stdio.h>
#include<malloc.h>
#define max 5
struct queue1
{
    int data;
    struct queue1 *link;
};
struct queue1 *front=NULL,*rear=NULL;
void push()
{
    struct queue1 *temp;
    temp=(struct queue1*)malloc(sizeof(struct queue1));
    printf("enter the element \n");
        scanf("%d",&temp->data);
        temp->link=NULL;
    if(rear==NULL)
    {
        rear=temp;
        front=rear;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
void pop()
{
    struct queue1 *temp;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
    else
    {
        temp=front;
        front=front->link;
        printf("the pope element is %d",temp->data);
        free(temp);
    }
}
void display()
{
    struct queue1 *temp;
    temp=front;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
        do
        {

            printf("%d \t",temp->data);
            temp=temp->link;
        }while(temp!=NULL);

}
int isEmpty()
{
    if(front==NULL)
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
