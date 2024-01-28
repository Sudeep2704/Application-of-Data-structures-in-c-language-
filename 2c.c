//WAP to represent a given sparse matrix in 3-tuple format using 2-D array

#include <stdio.h>

int main() {
    int row, col, i, j, count = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    int matrix[row][col];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    // Create a 2-D array for 3-tuple representation
    int sparseMatrix[count + 1][3];
    sparseMatrix[0][0] = row;
    sparseMatrix[0][1] = col;
    sparseMatrix[0][2] = count;

    // Fill the 3-tuple representation
    int k = 1;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Print the 3-tuple representation
    printf("\n3-Tuple Representation:\n");
    for (i = 0; i <= count; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
