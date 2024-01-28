#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef struct {
    Node *top;
} Stack;
void initialize(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
int is_empty(Stack *stack);
void display(Stack *stack);
int main() {
    Stack stack;
    initialize(&stack);
    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                if (!is_empty(&stack)) {
                    data = pop(&stack);
                    printf("Popped element: %d\n", data);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                if (is_empty(&stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
void initialize(Stack *stack) {
    stack->top = NULL;
}
void push(Stack *stack, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Element %d pushed onto the stack.\n", data);
}
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow. Exiting.\n");
        exit(EXIT_FAILURE);
    }
    int data = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
int is_empty(Stack *stack) {
    return stack->top == NULL;
}
void display(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
