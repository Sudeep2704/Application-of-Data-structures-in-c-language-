//WAP to represent the polynomial of single variable using 1-D array and perform the
//addition of two polynomial equations.

#include <stdio.h>

// Define the maximum degree of the polynomial
#define MAX_DEGREE 100

// Function to input a polynomial
void inputPolynomial(int poly[], int *degree) {
    printf("Enter the degree of the polynomial: ");
    scanf("%d", degree);

    printf("Enter the coefficients from highest degree to lowest degree:\n");
    for (int i = *degree; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

// Function to add two polynomials
void addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int result[], int *resultDegree) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;
    *resultDegree = maxDegree;

    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
        if (i <= degree1) {
            result[i] += poly1[i];
        }
        if (i <= degree2) {
            result[i] += poly2[i];
        }
    }
}

// Function to display a polynomial
void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i == degree) {
                printf("%dx^%d ", poly[i], i);
            } else {
                if (poly[i] > 0) {
                    printf("+ ");
                } else {
                    printf("- ");
                }
                printf("%dx^%d ", abs(poly[i]), i);
            }
        }
    }
    printf("\n");
}

int main() {
    int poly1[MAX_DEGREE + 1] = {0};
    int poly2[MAX_DEGREE + 1] = {0};
    int result[MAX_DEGREE + 1] = {0};
    int degree1, degree2, resultDegree;

    printf("Enter the first polynomial:\n");
    inputPolynomial(poly1, &degree1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(poly2, &degree2);

    addPolynomials(poly1, degree1, poly2, degree2, result, &resultDegree);

    printf("Result of addition:\n");
    displayPolynomial(result, resultDegree);

    return 0;
}
