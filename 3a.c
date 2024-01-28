// WAP to perform transpose of a given sparse matrix in 3-tuple format

#include <stdio.h>

int main() {
    int sparseMatrix[100][3];  // 3-tuple representation of the original sparse matrix
    int transposeMatrix[100][3];  // 3-tuple representation of the transpose matrix
    int numElements, numRows, numCols;

    // Read the 3-tuple representation of the original sparse matrix
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &numRows, &numCols);

    printf("Enter the 3-tuple representation (row, column, value):\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }

    // Transpose the matrix by swapping rows and columns
    transposeMatrix[0][0] = numCols;
    transposeMatrix[0][1] = numRows;
    transposeMatrix[0][2] = numElements;

    for (int i = 1; i <= numElements; i++) {
        transposeMatrix[i][0] = sparseMatrix[i - 1][1];
        transposeMatrix[i][1] = sparseMatrix[i - 1][0];
        transposeMatrix[i][2] = sparseMatrix[i - 1][2];
    }

    // Print the 3-tuple representation of the transpose matrix
    printf("\n3-Tuple Representation of the Transpose Matrix:\n");
    for (int i = 0; i <= numElements; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposeMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
