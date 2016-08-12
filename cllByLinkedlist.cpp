#include<stdio.h>
#include<malloc.h>
struct ll
{
    int data;
    struct ll *link;
};
struct ll *last=NULL;
void insert_beg(int data)
{
    struct ll *temp;
    temp=(struct ll*)malloc(sizeof(struct ll));
    if(last==NULL)
    {
        temp->data=data;
        last=temp;
        last->link=last;
    }
    else
    {
        temp->data=data;
        temp->link=last->link;
        last->link=temp;
    }
}
void insert_middle(int data, int position)
{
    struct ll *temp,*p;
    p=last;
    temp=(struct ll*)malloc(sizeof(struct ll));
    if(last==NULL)
    {
        temp->data=data;
        last=temp;
        last->link=last;
    }
    else
    {
        for(int i=1;i<position-1;i++)
            p=p->link->link;
        temp->data=data;
        temp->link=p->link;
        p->link=temp;
    }
}
void insert_end(int data)
{
    struct ll *temp,*p;
    p=last;
    temp=(struct ll*)malloc(sizeof(struct ll));
    if(last==NULL)
    {
        temp->data=data;
        last=temp;
        last->link=last;
    }
    else
    {
        temp->data=data;
        temp->link=last->link;
        last->link=temp;
        last=temp;
    }
}
void del_beg()
{
    struct ll *temp,*p;
    p=last;
    if(last==NULL)
    {
        printf("the list is empty\n");
    }
    else if(last=last->link)
    {
        last=NULL;
    }
    else
    {
        temp=last->link;
        last->link=last->link->link;
        free(temp);
    }
}
void del_middle(int position)
{
    struct ll *temp,*p;
    p=last->link;
    if(last==NULL)
    {
        printf("the list is empty\n");
    }
    else if(last==last->link)
    {
        last=NULL;
    }
    else
    {
        for(int i=1;i<position-1;i++)
            p=p->link;
        temp=p->link;
        p->link=p->link->link;
        printf("the deleted data is %d",temp->data);
        free(temp);
    }
}
void del_end()
{
    struct ll *temp,*p;
    p=last->link;
    if(last==NULL)
    {
        printf("the list is empty\n");
    }
    else if(last==last->link)
    {
        last=NULL;
    }
    else
    {
        while(p->link!=last)
            p=p->link;
        temp=p->link;
        p->link=last->link;
        last=p;
        free(temp);
    }
}
void display()
{
    struct ll *temp,*p;
    p=last;
    if(last==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        do
        {
            printf("%d\t",p->link->data);
            p=p->link;

        }while(p!=last);
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
    if(last==NULL)
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
