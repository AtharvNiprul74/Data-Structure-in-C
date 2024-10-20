//24UAM310:C program to implement linked list in c. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Node not created.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMid(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) 
    {
        insertAtBeginning(head, data);
        return;
    }
    
    struct Node* temp = *head;
    for (int i=0; temp!=NULL && i<position - 1; i++) 
    {
        temp = temp->next;
    }
    
    if (temp == NULL) 
    {
        printf("Position out of bounds. Inserting at the end.\n");
        insertAtEnd(head, data);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next; 
    free(temp); 
}


void deleteAtEnd(struct Node** head) {
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head); 
        *head = NULL;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    free(temp->next); 
    temp->next = NULL; 
}

struct Node* searchNode(struct Node* head, int data) {
    struct Node* current_node = head;
    while (current_node != NULL) {
        if (current_node->data == data) 
        {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL; 
}


void traverse(struct Node* head) {
    struct Node* curr_node = head;
    while (curr_node != NULL) {
        printf("%d,", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int ch, data, pos;

    while (1) {
        printf("\nLinked List in C.");
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Mid (Position)\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Search Node in List\n");
        printf("7. Traverse List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtMid(&head, data, pos);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (searchNode(head, data)) {
                    printf("%d found in the list.\n", data);
                } else {
                    printf("%d not found in the list.\n", data);
                }
                break;
            case 7:
                printf("Linked List: ");
                traverse(head);
                break;
            case 8:
                freeList(&head); 
                printf("Exit..\n");
                return 0; 
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

