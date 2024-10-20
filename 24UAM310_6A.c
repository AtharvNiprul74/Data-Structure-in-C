//24UAM310:C program to implement stack using array.
#include <stdio.h>

int push(int stack[], int *sttop, int stsize, int data) {
    if (*sttop >= (stsize-1)) 
    {
        return 0;
    } 
    else 
    {
        (*sttop)++;
        stack[*sttop] = data;
        return 1;
    }
}

int pop(int stack[], int *sttop, int *data) {
    if (*sttop < 0) 
    {
        return 0;
    } 
    else
    {
        *data = stack[*sttop];
        (*sttop)--;
        return 1;
    }
}

int main() {
    int stack[10];
    int top = -1;
    int size = 10;
    int ch = -1;
    int val;
    int retval;

    printf("Stack in C.\n");
    printf("\n1. Push\n2. Pop\n3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter data: ");
            scanf("%d", &val);
            retval = push(stack, &top, size, val);
            if (retval == 0) {
                printf("Stack is full");
            } else {
                printf("Data entered successfully.");
            }
        } 
        else if (ch == 2) {
            retval = pop(stack, &top, &val);
            if (retval == 0) {
                printf("Stack is empty");
            } else {
                printf("Popped data: %d", val);
            }
        } 
        else if (ch == 3) {
            printf("Exiting...");
            break;
        } 
        else {
            printf("Invalid choice.");
        }
    }

    return 0;
}

