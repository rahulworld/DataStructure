#include<stdio.h>
#include<malloc.h>
#define max 5
struct stack1
{
    int data[max];
    int top;
}a;
void push()
{
    int k;
    if(isFull())
    {
        printf("stack is overflow");
        return;
    }
    else
    {
        printf("enter the element \n");
        scanf("%d",&k);
        a.top=a.top+1;
        a.data[a.top]=k;
    }
}
void pop()
{
    int k;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
    else
    {
        k=a.data[a.top];
        a.top--;
        printf("the poped element is %d",k);
    }

}
void display()
{
    int k;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
    else
    {
        for(k=0;k<=a.top;k++)
        {
            printf("%d\t",a.data[k]);
        }
    }

}
int isEmpty()
{
    if(a.top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(a.top==max-1)
        return 1;
    else
        return 0;

}
main()
{
    int ch,choice,n=1;
    a.top=-1;
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
