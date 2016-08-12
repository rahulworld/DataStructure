#include<stdio.h>
#include<malloc.h>
struct crll
{
    int info;
    struct crll *link;
};
struct crll *last=NULL;
struct crll* getnode()
{
    struct crll* temp;
    temp=(struct crll*)malloc(sizeof(struct crll));
    return temp;
}
void insert_atbegin(int key)
{
    struct crll* new_node=getnode();
    if(last==NULL)
    {
        new_node->info=key;
        new_node->link=new_node;
        last=new_node;
    }
    else
    {
        new_node->info=key;
        new_node->link=last->link;
        last->link=new_node;
    }
}
void insert_atend(int key)
{
    struct crll* new_node=getnode();
    struct crll* t;
    t=last;
    if(last==NULL)
    {
        new_node->info=key;
        new_node->link=new_node;
        last=new_node;
    }
    else
    {

        new_node->info=key;
        new_node->link=last->link;
        last->link=new_node;
        last=new_node;
    }
}
void del(int key)
{
    struct crll* t, *tmp;
    t=last->link;
    if(last==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if(last->link==last && key==t->info)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return;
    }
    if(last->link->info==key)
    {
        tmp=last->link;
        last->link=last->link->link;
        free(tmp);
        return;
    }
    while(key==t->link->info && t->link!=last)
        t=t->link;
    if(t->link->info==key)
    {
        tmp=t->link;
        t->link=t->link->link;
        free(tmp);
    }
    if(last->info==key)
    {
        tmp=last;
        t->link=last->link;
        free(tmp);
    }
}
void display()
{
    struct crll* t;
    if(last==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        t=last;
        do
        {
            printf("%d\t",t->info);
            t=t->link;
        }while(t!=last);
    }
}
main()
{
    int ch,k;
    while(1){
        printf("1. insert at begging 2. insert at end 2. insert at position 4.display 5. delete\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the number which is inserted\n");
                scanf("%d",&k);
                insert_atbegin(k);
            break;
            case 2:
                printf("enter the number which is inserted\n");
                scanf("%d",&k);
                insert_atend(k);
            break;
            case 3:
                printf("enter the number which is inserted\n");
                scanf("%d",&k);
                insert_atbegin(k);
            break;
            case 4:
                display();
            break;
            case 5:
                printf("enter the number which is inserted\n");
                scanf("%d",&k);
                del(k);
            break;
        }
    }
}
