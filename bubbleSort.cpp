#include<stdio.h>
int n=6;
void bubble(int n)
{
    int a[n];
    printf("enter the element for sorting\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
main()
{
    bubble(n);
}
