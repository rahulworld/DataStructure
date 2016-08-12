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
    //for selection sort
    int temp;
    for(int i=0;i<n-1;i++)
    {
        minm=a[i];
        loc=i;
        for(int j=i+1;j<n-1;j++)
        {
            if(a[j]<minm)
            {
                minm=a[j];
                loc=j;
            }
        }
        if(loc!=i)
        {
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
        }
    }
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
main()
{
    selection(n);
}
