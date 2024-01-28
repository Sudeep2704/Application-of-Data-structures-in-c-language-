#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

//  creation a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//  insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//  search for an element in the list
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; 
}

// Function to sort the linked list in ascending order (Bubble Sort)
void sort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }

    int swapped, temp;
    struct Node* current;
    struct Node* lastSorted = NULL;

    do {
        swapped = 0;
        current = *head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap data
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

// Function to reverse the linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    *head = prev; // Updation of the head to new node first
}

// Function for displaying the  list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, choice, element, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &element);
        insertEnd(&head, element);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Search an element\n");
        printf("2. Sort the list in ascending order\n");
        printf("3. Reverse the list\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = search(head, element);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in the list\n");
                }
                break;
            case 2:
                sort(&head);
                printf("List sorted in ascending order\n");
                break;
            case 3:
                reverse(&head);
                printf("List reversed\n");
                break;
            case 4:
                printf("Linked List: ");
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
