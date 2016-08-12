#include<stdio.h>
#include<malloc.h>
struct node
{
    struct node *lchild;
    struct node *rchild;
    int info;
};
struct node *search(struct node *ptr,int skey)
{
    if(ptr==NULL)
    {
        printf("key is not found\n");
        return NULL;
    }
    else if(skey<ptr->info)
        return search(ptr->lchild,skey);
    else if(skey>ptr->info)
        return search(ptr->rchild,skey);
    else
        return ptr;
}
struct node *insert(struct node *ptr,int ikey)
{
    if(ptr==NULL)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->info=ikey;
        ptr->rchild=NULL;
        ptr->lchild=NULL;
    }
    else if(ikey<ptr->info)
        ptr->lchild=insert(ptr->lchild,ikey);
    else if(ikey>ptr->info)
        ptr->rchild=insert(ptr->rchild,ikey);
    else
        printf("Duplicate key\n");
        return ptr;

}
struct node *del(struct node *ptr,int dkey)
{
    struct node *tmp,*succ;
    if(ptr==NULL)
    {
        printf("dkey not found\n");
        return ptr;
    }
    if(dkey<ptr->info)
        ptr->lchild=del(ptr->lchild,dkey);
    else if(dkey>ptr->info)
        ptr->rchild=del(ptr->rchild,dkey);
        else
        {
            if(ptr->lchild!=NULL && ptr->rchild!=NULL)
            {
                succ=ptr->rchild;
                while(succ->lchild!=NULL)
                    succ=succ->lchild;
                ptr->info=succ->info;
                ptr->rchild=del(ptr->rchild,succ->info);
            }
            else
            {
                tmp=ptr;
                if(ptr->lchild!=NULL)
                ptr=ptr->lchild;
                else if(ptr->rchild!=NULL)
                    ptr=ptr->rchild;
                else
                    ptr=NULL;
                free(tmp);
            }
        }
        return ptr;
}
struct node *min(struct node *ptr)
{
    if(ptr==NULL)
        return NULL;
    else if(ptr->lchild==NULL)
        return ptr;
    else
        return min(ptr->lchild);
}
struct node *max(struct node *ptr)
{
if(ptr==NULL)
        return NULL;
    else if(ptr->rchild==NULL)
        return ptr;
    else
        return max(ptr->rchild);
}
void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
    printf("%d \t",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
    }
    else
        return;
}
void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
    inorder(ptr->lchild);
    printf("%d \t",ptr->info);
    inorder(ptr->rchild);
    }
    else
        return;
}
void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d \t",ptr->info);
    }
    else
        return;
}
int height(struct node *ptr)
{

}
main()
{
    struct node* root=NULL,*ptr;
    int ch,choice,n=1,k;
    while(n==1)
    {
        printf("\n 1. search 2. insert 3. delete 4. preorder 5. inorder \n 6.postorder 7.hieght of tree 8. find min and max \n enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the key to be searched\n");
                scanf("%d",&k);
                ptr=search(root,k);
                if(ptr==NULL)
                    printf("key is not present\n");
                    else
                        printf("key is present\n");
                break;
            case 2:
                printf("enter the key to be inserted\n");
                scanf("%d",&k);
                root=insert(root,k);
                break;
            case 3:
                printf("enter the key to be deleted\n");
                scanf("%d",&k);
                root=search(root,k);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                inorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                printf("height of tree is %d\n",height(root));
                break;
            case 8:
                ptr=min(root);
                if(ptr!=NULL)
                    printf("Min key is %d\n",ptr->info);
                ptr=max(root);
                if(ptr!=NULL)
                    printf("Max key is %d\n",ptr->info);
                break;
            default:
                printf("Invalid Choice");
        }
    }
}
