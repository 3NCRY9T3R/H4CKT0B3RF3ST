#include<stdio.h>
void insSort(int arr[],int n)
{
    int i,j,key;
    for(j=1;j<n;j++)
    {
        key=arr[j];
        i=j-1;
        while (i>=0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}
int main()
{
    int arr[10],n,i;
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n Enter the array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   
    printf("\n The inserted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    insSort(arr,n);
    printf("\n The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;    
}
