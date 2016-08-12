//this program work normally like simple queue
//beacause delete pointer then pointer free
#include<stdio.h>
#include<malloc.h>
struct Q
{
    int data;
    int priority;
    struct Q *link;
};
struct Q *frnt=NULL;
int isEmpty()
{
    if(frnt==NULL)
        return 1;
    else
        return 0;
}
void push()
{
    struct Q *temp,*p;
    p=frnt;
    temp=(struct Q*)malloc(sizeof(struct Q));
    printf("enter the element \n");
        scanf("%d",&temp->data);
    printf("enter the priority\n");
    scanf("%d",&temp->priority);
    temp->link=NULL;
    //that a one condition for empty and highet priority
    if(frnt==NULL||temp->priority<frnt->priority)
    {
        temp->link=frnt;
        frnt=temp;
    }
    else
    {
        //important condition
        while(p->link!=NULL && p->link->priority<=temp->priority)
            p=p->link;
        temp->link=p->link;
        p->link=temp;
    }
}
void pop()
{
    struct Q *temp;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
    else
    {
        temp=frnt;
        frnt=frnt->link;
        printf("the pope element is %d",temp->data);
        free(temp);
    }
}
void display()
{
    struct Q *temp;
    temp=frnt;
    if(isEmpty())
    {
        printf("stack is Empty \n");
        return;
    }
        while(temp!=NULL){
            printf("%d \t %d \n",temp->data,temp->priority);
            temp=temp->link;
        }
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
