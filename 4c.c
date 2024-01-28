#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

//  insert a term into a polynomial in descending order of exponents
void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (*poly == NULL || exponent > (*poly)->exponent) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL && current->next->exponent > exponent) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

//  add two polynomial equations
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly2->exponent > poly1->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            // Add coefficients with the same exponent
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) {
                insertTerm(&result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

// display a polynomial equation
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0");
    } else {
        while (poly != NULL) {
            printf("%d", poly->coefficient);
            if (poly->exponent > 0) {
                printf("x^%d", poly->exponent);
            }
            if (poly->next != NULL) {
                printf(" + ");
            }
            poly = poly->next;
        }
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    // Input for polynomial 1
    int n1, coefficient, exponent;
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the terms of polynomial 1 (coefficient exponent):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    // Input for polynomial 2
    int n2;
    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter the terms of polynomial 2 (coefficient exponent):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("Sum: ");
    displayPolynomial(result);

    // Free memory
    while (poly1 != NULL) {
        struct Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        struct Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        struct Term* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
