//WAP to create a 1-D array of n elements and perform the following menu based operations
//usingfunction.
//a. insert a given element at specific position.
//b. delete an element from a specific position of the array.
//c. linear search to search an element
//d. traversal of the array


#include <stdio.h>
// To display the array
int i;
void displayarray(int arr[], int size) {
printf("array elements - ");
for(i=0; i < size; i++) {
printf("%d", arr[i]);
}
printf("\n");}

// to insert a element at a position
void insertElement(int arr[], int *size, int position, int element) {
if (position < 0 || position > *size) {
printf("Invalid position\n");
return;
}
for (int i = *size; i > position; i--) { // to shift position of the element to make space
arr[i] = arr[i - 1];}
arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

// to delete a value at specific position
void deleteElement(int arr[], int *size, int position) {
if (position < 0 || position >= *size) {
printf("Invalid position\n");
return;
}
for (int i = position; i < *size - 1; i++) {
arr[i] = arr[i + 1];
}

(*size)--;
printf("Element deleted successfully.\n"); // shift to remove element to left
}

// linear search
int linearSearch(int arr[], int size, int target) {
for (int i = 0; i < size; i++) {
if (arr[i] == target) {
return i; } 
}
return -1;
}
int main() {
int n;
printf("Enter the size of the array: ");
scanf("%d", &n);
int arr[100]; // Assume max array sz 100
int size = 0;

printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
size++;
}

int choice;
do {
printf("\nMenu:\n");
printf("1. Display array\n");
printf("2. Insert element\n");
printf("3. Delete element\n");
printf("4. Linear search\n");
printf("5. Traversal of array\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
displayarray(arr, size);
break;

case 2: {
int position, element;
printf("Enter position to insert: ");
scanf("%d", &position);
printf("Enter element to insert: ");
scanf("%d", &element);
insertElement(arr, &size, position, element);
break;
}
case 3: {
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            }

            case 4: {
                int target;
                printf("Enter element to search: ");
                scanf("%d", &target);
                int index = linearSearch(arr, size, target);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }

            case 5:
                printf("Array elements:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 6);

    return 0;
}






    
    
    
    
    
    
    
    
    
    
    
    
    
    