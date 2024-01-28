#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the circular queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the circular queue is full
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to enqueue (insert) into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to dequeue (delete) from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued %d\n", circularQueue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// Function to traverse and print the circular queue
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        do {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. IsEmpty\n5. IsFull\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                traverse();
                break;

            case 4:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 5:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;

            case 0:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
