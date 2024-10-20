//24UAM310:C program to implement static list(array).
#include <stdio.h>

void shiftDown(int arr[], int size, int pos) {
    for (int i=size; i>pos; i--) 
    {
        arr[i] = arr[i-1];  
    }
}

void shiftUp(int arr[], int size, int pos) {
    for (int i=pos; i<size - 1; i++) 
    {
        arr[i] = arr[i+1];  
    }
}

void insertAtpos(int arr[], int *size, int value, int pos) {
    if (*size >= 10) {
        printf("Array is full.\n");
        return;   
    }
    if (pos<0 || pos>*size) {
        printf("Position is invalid.\n");
        return;
    }
    shiftDown(arr, *size, pos);  
    arr[pos] = value;              
    (*size)++;
}

void deleteAtpos(int arr[], int *size, int pos) {
    if (*size <= 0) 
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *size) 
    {
        printf("Invalid pos.\n");
        return;
    }
    shiftUp(arr, *size, pos);  
    (*size)--;
}

void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i; 
        }
    }
    return -1;  
}

int main() {
    int arr[10];
    int size = 0;
    int ch, value, pos;

    printf("Static List\n");
    while (1) {
        printf("\nStatic List Implementation in C");
        printf("\nMenu:\n");
        printf("1. Insert at position.\n");
        printf("2. Delete at position.\n");
        printf("3. Traverse array\n");
        printf("4. Search for an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter pos: ", size);
                scanf("%d", &pos);
                insertAtpos(arr, &size, value, pos);
                break;
            case 2:
                printf("Enter pos to delete: ", size-1);
                scanf("%d", &pos);
                deleteAtpos(arr, &size, pos);
                break;
            case 3:
                traverse(arr, size);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(arr, size, value);
                if (pos != -1) {
                    printf("Value %d found at pos %d.\n", value, pos);
                } else {
                    printf("Value %d not found.\n", value);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

