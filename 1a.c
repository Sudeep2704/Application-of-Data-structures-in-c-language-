// Compare the numbers DS handout 1.11


#include <stdio.h>
void compareNumbers(int *num1, int *num2) {
    if (*num1 > *num2) {
        printf("First number is greater.\n");
    } else if (*num1 < *num2) {
        printf("Second number is greater.\n");
    } else {
        printf("Both numbers are equal.\n");
    }
}
int main() {
    int number1, number2;
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);
    compareNumbers(&number1, &number2);
    return 0;
}
