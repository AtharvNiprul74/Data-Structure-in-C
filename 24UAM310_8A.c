//24UAM310:C program to implement linear search.
#include <stdio.h>

int linearSearch(int arr[],int searchElement,int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==searchElement)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int arr[40],size,searchElement;
    printf("Enter No of elements:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter Element you want to search:");
    scanf("%d",&searchElement);
    int index=linearSearch(arr,searchElement,size);
    if(index!=-1)
    {
        printf("Value is found at %d index.",index);
    }
    else
    {
        printf("Value is not found in given list.");
    }
}