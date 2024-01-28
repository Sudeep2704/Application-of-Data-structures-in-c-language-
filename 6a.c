#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
  if (top == MAX_SIZE - 1) {
    printf("Stack is full!\n");
    return;
  }

  top++;
  stack[top] = data;
}

int pop() {
  if (top == -1) {
    printf("Stack is empty!\n");
    return -1;
  }

  int data = stack[top];
  top--;
  return data;
}

int isEmpty() {
  return top == -1;
}

int isFull() {
  return top == MAX_SIZE - 1;
}

void display() {
  if (isEmpty()) {
    printf("Stack is empty!\n");
    return;
  }

  for (int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main() {
  int choice, data;

  while (1) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check if empty\n");
    printf("4. Check if full\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        break;

      case 2:
        data = pop();
        if (data != -1) {
          printf("Popped element: %d\n", data);
        }
        break;

      case 3:
        if (isEmpty()) {
          printf("Stack is empty!\n");
        } else {
          printf("Stack is not empty!\n");
        }
        break;

      case 4:
        if (isFull()) {
          printf("Stack is full!\n");
        } else {
          printf("Stack is not full!\n");
        }
        break;

      case 5:
        display();
        break;

      case 6:
        exit(0);

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}