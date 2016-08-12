#include<stdio.h>
#define m 6
//merge Sort
void merge_(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
    int i=low1;
    int j=low2;
    int k=low1;
    while((i<=up1)&&(j<=up2))
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=up1)
        temp[k++]=arr[i++];
    while(j<=up2)
        temp[k++]=arr[j++];
}
void copy_(int arr[],int temp[],int low, int up)
{
    int i;
    for(i=low;i<=up;i++)
        arr[i]=temp[i];
}
void merge_sort(int arr[],int low, int up)
{
    int mid=(low+up)/2;
    int temp[m];
    if(low<up)
    {
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,up);
        merge_(arr,temp,low,mid,mid+1,up);
        copy_(arr,temp,low,up);
    }
}
main()
{
    int arr[m];
    printf("enter the element for sorting\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,m-1);
    for(int i=0;i<m;i++)
        printf("%d\t",arr[i]);
}
