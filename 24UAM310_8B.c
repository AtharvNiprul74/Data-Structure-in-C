//24UAM310:C program to implement binary search.
#include <stdio.h>

int binarySearch(int arr[],int low,int high,int mid,int data)
{
  
  while(low<=high)
  {
    mid=low+high/2;
     
    if(arr[mid]==data)
    {
        return mid;
    }
    else if(arr[mid]<data)
    {
        low= mid+1;
    }
    else
    { 
        high=mid-1;
    }
  
  }
  return -1;
}

void main()
{
    int arr[20],size,high=20,low=0,mid,searchElement;
    printf("Enter no of elements:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search:");
    scanf("%d",&searchElement);
    int index=binarySearch(arr,low,high,mid,searchElement);
    if(index==-1)
    {
        printf("Element not found in the list.");
    }
    else
    {
        printf("Element found at index %d.",index);
    }
}