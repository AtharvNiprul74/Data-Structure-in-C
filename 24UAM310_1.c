//24UAM310_1:C program to calculate standard devation.
#include <stdio.h>
#include <math.h>

int average(int arr[],int len);
int x_bar(int arr[],int len,int avg);

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
    int avg=average(arr,len);
    int standerd_dev=x_bar(arr,len,avg);
    printf("Standard Devation=%d",standerd_dev);
}

int average(int arr[],int len)
{
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum=sum+arr[i];
    }
    int avg=sum/len;
    return avg;
}

int x_bar(int arr[],int len,int avg)
{
    int x_bar_array[100];
    for(int i=0;i<len;i++)
    {
        x_bar_array[i]=arr[i]-avg;
    }
    
    for(int i=0;i<len;i++)
    {
        x_bar_array[i]=x_bar_array[i]*x_bar_array[i];
    }
    
    int x_avg=average(x_bar_array,len);
    int dev=sqrt(x_avg);
    return dev;
}