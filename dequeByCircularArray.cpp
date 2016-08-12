#include<stdio.h>
#include<malloc.h>
#define max1 6
int frnt=-1,rear=-1;
int dequeue[max1];
int isFull()
{
    if((rear==max1-1 && frnt==0)||(frnt==rear+1))
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(frnt==-1)
        return 1;
    else
        return 0;
}
void insert_front()
{
    int k;
    printf("enter the elment\n");
    scanf("%d",&k);
    if(isFull())
    {
        printf("The queue is overflow\n");
        return;
    }
    if(frnt==-1)
    {
        frnt=0;
        rear=0;
    }
    else if(frnt==0)
    {
        frnt=max1-1;
    }
    else
    {
        frnt=frnt-1;
    }
        dequeue[frnt]=k;
}
void insert_rear()
{
    int k;
    printf("enter the elment\n");
    scanf("%d",&k);
    if(isFull())
    {
        printf("The queue is overflow\n");
        return;
    }
    if(frnt==-1)
    {
        frnt=0;
        rear=0;
    }
    else if(rear==max1-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
        dequeue[rear]=k;
}
void del_front()
{
    if(isEmpty())
    {
        printf("the queue is underflow\n");
        return;
    }
    printf("the deleted element is %d",dequeue[frnt]);
    if(frnt==rear)
    {
        frnt=rear=-1;
    }
    else if(frnt==max1-1)
    {
        frnt=0;
    }
    else
    {
        frnt=frnt+1;
    }
}
void del_rear()
{
    if(isEmpty())
    {
        printf("the queue is empty\n");
        return;
    }
        printf("the deleted element is %d",dequeue[rear]);
    if(frnt==rear)
    {
        frnt=rear=-1;
    }
    if(rear==0)
    {
        rear=max1-1;

    }
    else
    {
        rear=rear-1;

    }

}
void display()
{
    int i;
    i=frnt;
    if(isEmpty())
    {
        printf("the queue is underflow\n");
        return;
    }
    if(frnt<=rear)
    {
        while(i<=rear)
            printf("%d\t",dequeue[i++]);
        //for(int i=frnt;i<=rear;i++)
    }
    else
    {
        while(i<=(max1-1))
            printf("%d\t",dequeue[i++]);
        i=0;
        while(i<=rear)
            printf("%d\t",dequeue[i++]);
    }
}
main()
{
    int ch,choice,n=1;
    while(1)
    {
        printf("\n 1. insert from front 2. insert from rear 3. delete from front 4. delete from rear 5. display 6. exit \n enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_front();
                break;
            case 2:
                insert_rear();
                break;
            case 3:
                del_front();
                break;
            case 4:
                del_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Invalid Choice");
        }
    }
}
