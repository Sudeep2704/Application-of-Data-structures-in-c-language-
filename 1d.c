// 1.4 assignment 


#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

void multiplyComplex(struct Complex *num1, struct Complex *num2) {
    float real_part = num1->real * num2->real - num1->imag * num2->imag;
    float imag_part = num1->real * num2->imag + num1->imag * num2->real;
    num1->real = real_part;
    num1->imag = imag_part;
}

int main() {
    struct Complex num1, num2, result;
    int choice;

    printf("Enter real and imaginary part of the first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary part of the second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    printf("\nMenu:\n");
    printf("1. Addition of two complex numbers\n");
    printf("2. Multiplication of two complex numbers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = addComplex(num1, num2);
            printf("Sum: %.2f + %.2fi\n", result.real, result.imag);
            break;
        
        case 2:
            multiplyComplex(&num1, &num2);
            printf("Product: %.2f + %.2fi\n", num1.real, num1.imag);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
