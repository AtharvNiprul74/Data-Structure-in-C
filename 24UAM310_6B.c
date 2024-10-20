//24UAM310:C program to implement stack using linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int push(struct node **tptr, int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        return 0;
    } else {
        tmp->data = data;
        tmp->next = *tptr;
        *tptr = tmp;
        return 1;
    }
}

struct node *pop(struct node **tptr) {
    struct node *tmp;
    if (*tptr == NULL) {
        return NULL;
    } else {
        tmp = *tptr;
        *tptr = tmp->next;
        return tmp;
    }
}


int main() {
    struct node *top = NULL;
    struct node *retnode;
    int retval;
    int ch;
    int val;

    printf("Stack using Linked List.\n");
    printf("\n1. push\n2. pop \n3. exit\n");

    while (1) {
        printf("Enter your choice :");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter data:");
            scanf("%d", &val);
            retval = push(&top, val);
            if (retval == 0) {
                printf("stack is overflow.\n");
            } else {
                printf("Data pushed successfully.\n");
            }
        } 
        else if (ch == 2) {
            retnode = pop(&top);
            if (retnode == NULL) {
                printf("Stack is empty.");
            } else {
                printf("Popped data = %d\n", retnode->data);
                free(retnode);
            }
        } 
        else if (ch == 3) {
            printf("Exit.\n");
            break;
        } 
        else {
            printf("\nInvalid choice.");
        }
    }

    return 0;
}

