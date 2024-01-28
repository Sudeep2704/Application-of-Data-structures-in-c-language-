//WAP to perform addition of two given sparse matrix in 3–tuple format.


#include <stdio.h>

// Define a structure to represent a sparse matrix element in 3-tuple format
struct Element {
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix
void readSparseMatrix(struct Element matrix[], int *numRows, int *numCols, int *numElements) {
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", numRows, numCols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", numElements);

    printf("Enter the elements (row, col, value):\n");
    for (int i = 0; i < *numElements; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

// Function to add two sparse matrices
void addSparseMatrices(struct Element matrix1[], int numRows1, int numCols1, int numElements1,
                       struct Element matrix2[], int numRows2, int numCols2, int numElements2,
                       struct Element resultMatrix[], int *numRowsResult, int *numColsResult, int *numElementsResult) {
    if (numRows1 != numRows2 || numCols1 != numCols2) {
        printf("Matrix dimensions do not match. Addition not possible.\n");
        return;
    }

    *numRowsResult = numRows1;
    *numColsResult = numCols1;
    int i = 0, j = 0, k = 0;

    while (i < numElements1 && j < numElements2) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            resultMatrix[k++] = matrix1[i++];
        } else if (matrix2[j].row < matrix1[i].row || (matrix2[j].row == matrix1[i].row && matrix2[j].col < matrix1[i].col)) {
            resultMatrix[k++] = matrix2[j++];
        } else {
            resultMatrix[k].row = matrix1[i].row;
            resultMatrix[k].col = matrix1[i].col;
            resultMatrix[k].value = matrix1[i].value + matrix2[j].value;
            k++;
            i++;
            j++;
        }
    }

    // Copy any remaining elements from matrix1 and matrix2
    while (i < numElements1) {
        resultMatrix[k++] = matrix1[i++];
    }

    while (j < numElements2) {
        resultMatrix[k++] = matrix2[j++];
    }

    *numElementsResult = k;
}

// Function to display a sparse matrix
void displaySparseMatrix(struct Element matrix[], int numRows, int numCols, int numElements) {
    printf("Sparse Matrix (%d x %d):\n", numRows, numCols);
    for (int i = 0; i < numElements; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    struct Element matrix1[100], matrix2[100], resultMatrix[200];
    int numRows1, numCols1, numElements1;
    int numRows2, numCols2, numElements2;
    int numRowsResult, numColsResult, numElementsResult;

    printf("Enter the first sparse matrix:\n");
    readSparseMatrix(matrix1, &numRows1, &numCols1, &numElements1);

    printf("Enter the second sparse matrix:\n");
    readSparseMatrix(matrix2, &numRows2, &numCols2, &numElements2);

    addSparseMatrices(matrix1, numRows1, numCols1, numElements1,
                      matrix2, numRows2, numCols2, numElements2,
                      resultMatrix, &numRowsResult, &numColsResult, &numElementsResult);

    printf("Resultant Sparse Matrix:\n");
    displaySparseMatrix(resultMatrix, numRowsResult, numColsResult, numElementsResult);

    return 0;
}
