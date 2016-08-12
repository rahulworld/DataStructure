#include<stdio.h>
#include<malloc.h>
#define max 3
struct queue1
{
    int data[max];
    int front,rear;
}a;

void push()
{
    if(isFull())
    {
        printf("queue is overflow \n");
        return;
    }
    //that is contdition for first insertion and or elsewhere insertion
    a.rear=a.rear+1;
    if(a.front=-1)
        a.front=0;
    printf("enter the element\n");
    scanf("%d",&a.data[a.rear]);
}
void pop()
{
    if(isEmpty())
    {
        printf("queue is eMpty");
        return;
    }
    printf("the poped element in the array is: %d",a.data[a.front]);
    a.front++;
}
void display()
{
    int k;
    for(k=a.front;k<=a.rear;k++)
    {
        printf("%d\t",a.data[k]);
    }

}
int isEmpty()
{
    //the two condtion is for when is queue is empty
    if(a.front==-1||a.front==a.rear+1)
        return 1;
    else
        return 0;
}
int isFull()
{
    //that is only condition for full queue
    if(a.rear==max-1)
        return 1;
    else
        return 0;
}
main()
{
    a.front=-1,a.rear=-1;
    int ch,choice,n=1;
    while(n==1)
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
