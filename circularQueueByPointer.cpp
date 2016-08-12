//this program work normally like simple queue
//beacause delete pointer then pointer free
#include<stdio.h>
#include<malloc.h>
#define max 5
struct queue1
{
    int data;
    struct queue1 *link;
};
struct queue1 *frnt=NULL,*rear=NULL;
int isEmpty()
{
    if(frnt==NULL)
        return 1;
    else
        return 0;
}
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
        rear->link=temp;
        frnt=rear;
    }
    else
    {
        rear->link=temp;
        rear=temp;
        rear->link=frnt;
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
        rear->link=rear->link->link;
        temp=frnt;
        frnt=frnt->link;
        printf("the pope element is %d",temp->data);
        free(temp);
    }
}
void display()
{
    struct queue1 *temp;
    temp=frnt;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
        do
        {

            printf("%d \t",temp->data);
            temp=temp->link;
        }while(temp!=rear);

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
