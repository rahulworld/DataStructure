#include<stdio.h>
#include<malloc.h>
struct ll
{
    int data;
    struct ll *frnt,*last;
};
struct ll *start=NULL;
void insert_beg(int data)
{
    struct ll *temp;
    temp=(struct ll*)malloc(sizeof(struct ll));
    if(start==NULL)
    {
        temp->data=data;
        temp->frnt=NULL;
        temp->last=NULL;
        start=temp;
    }
    else
    {
        temp->data=data;
        temp->last=start;
        start->frnt=temp;
        temp->frnt=NULL;
        start=temp;
    }
}
void insert_middle(int data, int position)
{
    struct ll *temp,*p;
    p=start;
    temp=(struct ll*)malloc(sizeof(struct ll));
    if(start==NULL)
    {
        temp->data=data;
        temp->frnt=NULL;
        temp->last=NULL;
        start=temp;
    }
    else
    {
        for(int i=1;i<position-1;i++)
            p=p->last;
            temp->data=data;
            temp->last=p->last;
            p->last->frnt=temp;
            temp->frnt=p;
            p->last=temp;
    }
}
void insert_end(int data)
{
    struct ll *temp,*p;
    p=start;
    temp=(struct ll*)malloc(sizeof(struct ll));
    if(start==NULL)
    {
        temp->data=data;
        temp->frnt=NULL;
        temp->last=NULL;
        start=temp;
    }
    else
    {
        while(p->last!=NULL)
            p=p->last;
        temp->data=data;
        temp->last=NULL;
        temp->frnt=p;
        p->last=temp;
    }
}
void del_beg()
{
    struct ll *temp,*p;
    p=start;
    if(start==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        temp=start;
        start=start->last;
        start->frnt=NULL;
        free(temp);
    }
}
void del_middle(int position)
{
    struct ll *temp,*p;
    p=start;
    if(start==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        for(int i=1;i<position-1;i++)
            p=p->last;
        temp=p->last;
        p->last=p->last->last;
        printf("the deleted data is %d",temp->data);
        free(temp);
    }
}
void del_end()
{
    struct ll *temp,*p;
    p=start;
    if(start==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        while(p->last->last!=NULL)
            p=p->last;
        temp=p->last;
        p->last=NULL;
        free(temp);
    }
}
void display()
{
    struct ll *temp,*p,*t;
    p=start;
    t=start;
    if(start==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        printf("the list from front\n");
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->last;
        }
        printf("the list font last\n");
        while(t->last!=NULL)
            t=t->last;
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->frnt;
        }
    }
}
void search_node(int data)
{

}
void reverse1()
{

}
int isEmpty()
{
    if(start==NULL)
        return 1;
    else
    return 0;
}
main()
{
    int ch,choice,n=1,d,p;
    while(n==1)
    {
        printf("\n 1. insert at begin 2. insert at middle 3. insert at end 4. delete at begin 5. delete at middle 6.delete at end\
               \n 7. display 8. search 9. reserval 10.exit \n enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the number which is insert in the list\n");
                scanf("%d",&d);
                insert_beg(d);
                break;
            case 2:
                printf("enter the number which is insert in the list\n");
                scanf("%d",&d);
                printf("enter the position which is insert in the list\n");
                scanf("%d",&p);
                insert_middle(d,p);
                break;
            case 3:
                printf("enter the number which is insert in the list\n");
                scanf("%d",&d);
                insert_end(d);
                break;
            case 4:
                del_beg();
                break;
            case 5:
                printf("enter the position which is insert in the list\n");
                scanf("%d",&p);
                del_middle(p);
                break;
            case 6:
                del_end();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("enter the number which is insert in the list\n");
                scanf("%d",&d);
                search_node(d);
                break;
            case 9:
                printf("enter the number which is insert in the list\n");
                scanf("%d",&d);
                reverse1();
                break;
            case 10:
                exit(1);
                break;
            default:
                printf("Invalid Choice");
        }
    }
}
