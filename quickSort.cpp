#include<stdio.h>
#define m 6
int parti_tion(int arr[],int low, int up)
{
    int i=low+1,j=up;
    int pivot=arr[low];
    int temp;
    while(i<=j)
    {
        while((pivot>arr[i])&& (i<up))
            i++;
        while(pivot<arr[j])
            j--;
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
    arr[low]=arr[j];
    arr[j]=pivot;
    return j;
}
void quick_sort(int arr[], int low, int up)
{
    int pivloc;
    if(low>up)
        return;
    //error coming in first functin of quick pivloc
    pivloc=parti_tion(arr,low,up);
    quick_sort(arr,low,pivloc-1);
    quick_sort(arr,pivloc+1,up);
}
main()
{
    int arr[m];
    printf("enter the element for sorting\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,m-1);
    for(int i=0;i<m;i++)
        printf("%d\t",arr[i]);
}
