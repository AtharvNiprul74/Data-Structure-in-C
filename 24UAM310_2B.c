// 24UAM310:C program to implement selection sort
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i=0; i<n-1; i++) {
        min=i;
        for (j=i+1; j<n;j++) {
            if (arr[j]<arr[min]) {
                min=j;
            }
        }

        if (min!=i) {
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}

void printArray(int arr[],int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int arr[num];
    
    for (int i = 0; i < num; i++) {
        printf("Enter %d element:",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, num);

    selectionSort(arr, num);

    printf("Sorted array: \n");
    printArray(arr, num);

    return 0;
}

