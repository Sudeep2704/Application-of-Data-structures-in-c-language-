#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// insertion of node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

//  insert a node at a specific position in the doubly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (*head == NULL) {
        if (position == 1) {
            *head = newNode;
        } else {
            printf("Invalid position!\n");
        }
    } else {
        struct Node* current = *head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current->next != NULL) {
            current = current->next;
            currentPosition++;
        }
        if (currentPosition == position - 1) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        } else {
            printf("Invalid position!\n");
        }
    }
}

// Function to delete a node from a specific position in the doubly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    if (position == 1) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
    } else {
        while (currentPosition < position && current->next != NULL) {
            current = current->next;
            currentPosition++;
        }
        if (currentPosition == position) {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
        } else {
            printf("Invalid position!\n");
        }
    }
}

// Function to traverse and display the doubly linked list in both directions
void traverseList(struct Node* head) {
    printf("Forward traversal: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");

    printf("Reverse traversal: ");
    while (head != NULL) {
        if (head->next == NULL) {
            printf("%d -> ", head->data);
        }
        head = head->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at the beginning\n");
        printf("2. Insert an element at a specific position\n");
        printf("3. Delete an element from a specific position\n");
        printf("4. Traverse the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 3:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
