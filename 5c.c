#include <stdio.h>
#include <stdlib.h>

// Define the structure for a non-zero element in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
    struct Element* next;
};

// Define the structure for the header node of the sparse matrix
struct HeaderNode {
    int numRows;
    int numCols;
    struct Element* nextRow;
    struct Element* nextCol;
};

// Function to create a new element node
struct Element* createElement(int row, int col, int value) {
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    if (newElement == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newElement->row = row;
    newElement->col = col;
    newElement->value = value;
    newElement->next = NULL;
    return newElement;
}

// Function to create a new header node
struct HeaderNode* createHeaderNode(int numRows, int numCols) {
    struct HeaderNode* newHeader = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    if (newHeader == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newHeader->numRows = numRows;
    newHeader->numCols = numCols;
    newHeader->nextRow = NULL;
    newHeader->nextCol = NULL;
    return newHeader;
}

// Function to insert an element into the sparse matrix
void insertElement(struct HeaderNode* header, int row, int col, int value) {
    struct Element* newElement = createElement(row, col, value);
    // Insert into the row list
    if (header->nextRow == NULL || header->nextRow->row > row) {
        newElement->next = header->nextRow;
        header->nextRow = newElement;
    } else {
        struct Element* current = header->nextRow;
        while (current->next != NULL && current->next->row <= row) {
            current = current->next;
        }
        newElement->next = current->next;
        current->next = newElement;
    }
    // Insert into the column list
    if (header->nextCol == NULL || header->nextCol->col > col) {
        newElement->next = header->nextCol;
        header->nextCol = newElement;
    } else {
        struct Element* current = header->nextCol;
        while (current->next != NULL && current->next->col <= col) {
            current = current->next;
        }
        newElement->next = current->next;
        current->next = newElement;
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct HeaderNode* header) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < header->numRows; i++) {
        for (int j = 0; j < header->numCols; j++) {
            struct Element* current = header->nextRow;
            int found = 0;
            while (current != NULL) {
                if (current->row == i && current->col == j) {
                    printf("%d ", current->value);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int numRows, numCols;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &numRows, &numCols);

    struct HeaderNode* header = createHeaderNode(numRows, numCols);

    int numNonZeroElements;
    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", &numNonZeroElements);

    for (int i = 0; i < numNonZeroElements; i++) {
        int row, col, value;
        printf("Enter element %d (row, col, value): ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            printf("Invalid row or column!\n");
            continue;
        }
        insertElement(header, row, col, value);
    }

    displaySparseMatrix(header);

    return 0;
}
