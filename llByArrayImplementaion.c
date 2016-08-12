#include<stdio.h>
#include<malloc.h>
#define max 5
struct nodetype
{
    int data;
    int next;
};
struct nodetype node[max];
int avail=0;
void initialize()
{
    int i;
    for(i=1;i<max;i++)
        node[i].next=i+1;
    node[max].next=-1;
}
void insertBeg(int data)
{
    if(avail==max)
    {
        printf("linked list is overflow\n");
        return;
    }
    else if(avail==0)
    {
        avail=1;
        node[avail].data=data;
        return;
    }
    else if(avail==max-1)
    {
        node[max].data=data;
        avail=max;
    }
    else
    {
        avail=node[avail].next;
        node[avail].data=data;
    }
}
void deleteAt(int data)
{
    int i,m=0,n=0;
    i=avail;
    if(avail==max)
    {
    for(m=1;m<=max;m++)
    {
        if(node[m].data==data)
        {
            n=m;
            break;
        }
    }
    if(n!=0)
    {
        avail=max-1;
        for(m=n;m<max;m++)
        {
            node[m].data=node[m+1].data;
        }
        printf("Your element deleted is %d\n",data);
    }
    }
    else
    {
    for(m=1;m<=i;m++)
    {
        if(node[m].data==data)
        {
            n=m;
            break;
        }
    }
    if(n!=0)
    {

        for(m=n;m<avail;m++)
        {
            node[m].data=node[m+1].data;
        }
        avail=node[avail-2].next;

        printf("Your element deleted is %d\n",data);
    }
    }
}
void display()
{
    int i;
    if(avail==0)
    {
        printf("ll is empty\n");
        return;
    }
    printf("serial no.\t node data \t node next\n");
    if(avail==-1)
    {
        for(i=1;i<=max;i++){
        printf("%d\t\t %d \t\t %d\t\n",i,node[i].data,node[i].next);
        }
    }
    else
    {
        for(i=1;i<=avail;i++)
        {
        printf("%d\t\t %d \t\t %d\t\n",i,node[i].data,node[i].next);
        }
    }
}
main()
{
    int ch,choice,n=1,d;
    initialize();
    while(n==1){
        printf("\n 1. insert 2. delete 3. display 4. break\n enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the number");
                scanf("%d",&d);
                insertBeg(d);
                break;
            case 2:
                printf("enter the number");
                scanf("%d",&d);
                deleteAt(d);
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
