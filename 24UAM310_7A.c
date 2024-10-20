// 24UAM310:C program to implement static circular queue.
#include <stdio.h>
#include <stdlib.h>

int isFull(int front, int rear, int SIZE) {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}


int isEmpty(int front) {
    return front == -1;
}

void enqueue(int queue[], int *front, int *rear, int SIZE) {
    int val;
    printf("Enter Value to Add: ");
    scanf("%d", &val);

    if (isFull(*front, *rear, SIZE)) {
        printf("Queue is full.\n");
        return;
    }

    if (*front == -1) 
        *front = 0;

    *rear = (*rear + 1) % SIZE;   
    queue[*rear] = val;
    printf("Element Enqueued!");
}

void dequeue(int queue[], int *front, int *rear, int SIZE) {
    if (isEmpty(*front)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Dequeued Element - %d\n", queue[*front]);

    if (*front == *rear) {
        *front = *rear = -1; 
    } else {
        *front = (*front + 1) % SIZE; 
    }
}

void display(int queue[], int *front, int *rear, int SIZE) {
    if (isEmpty(*front)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = *front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == *rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() 
{
    int SIZE = 5;
    int queue[SIZE];
    int front = -1;
    int rear = -1;
    int ch;

    while (1) {
        printf("\n1. Add Element to Queue\n2. Delete Element from Queue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue(queue, &front, &rear, SIZE);
                break;
            case 2:
                dequeue(queue, &front, &rear, SIZE);
                break;
            case 3:
                display(queue, &front, &rear, SIZE);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

