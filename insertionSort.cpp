#include<stdio.h>
int n=6;
void selection(int n)
{
    int a[n],minm,loc;
    printf("enter the element for sorting\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //for insertion sort
    int temp;
    for(int i=0;i<n-1;i++)
    {
        temp=a[i];
        for(int j=i-1;j>=0&&a[j]>temp;j--)
        {
            a[j+1]=a[j];
            a[j]=temp;
        }
    }
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
main()
{
    selection(n);
}
