
//Write a program to perform the following operations on a given square matrix using
//functions:
#include <stdio.h>

// Function to input a square matrix from the user
void inputMatrix(int matrix[100][100], int n) {
    printf("Enter elements of the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to count the number of nonzero elements in the matrix
int countNonzeroElements(int matrix[100][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int matrix[100][100], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d\t", matrix[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayDiagonalElements(int matrix[100][100], int n) {
    printf("Elements just above the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i + 1) {
                printf("%d\t", matrix[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("Elements just below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i - 1) {
                printf("%d\t", matrix[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix[100][100];
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    inputMatrix(matrix, n);

    int nonzeroCount = countNonzeroElements(matrix, n);
    printf("The number of nonzero elements in the matrix is: %d\n", nonzeroCount);

    displayUpperTriangular(matrix, n);

    displayDiagonalElements(matrix, n);

    return 0;
}
