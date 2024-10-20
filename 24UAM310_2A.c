//24UAM310:C program to implement Bubble sort.
#include <stdio.h>
void sort(int arr[],int len);
void main()
{
    int arr[100],len;
    printf("Enter No of elements:");
    scanf("%d",&len);
    for(int i=0;i<len;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    sort(arr,len);
}

void sort(int arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1;j++)
        {

            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Sorted Array=");
    for(int i=0;i<len;i++)
    {
        printf("%d\t",arr[i]);
    }
}