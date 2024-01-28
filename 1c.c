#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percentage;
    float da_percentage;
};

void calculateGrossSalary(struct Employee *emp) {
    emp->hra_percentage /= 100;
    emp->da_percentage /= 100;

    float hra = emp->basic_salary * emp->hra_percentage;
    float da = emp->basic_salary * emp->da_percentage;

    emp->basic_salary += hra + da;
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; ++i) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        employees[i].emp_id = i + 1;

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Designation: ");
        scanf("%s", employees[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);

        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hra_percentage);

        printf("DA Percentage: ");
        scanf("%f", &employees[i].da_percentage);

        calculateGrossSalary(&employees[i]);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; ++i) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Emp-ID: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Gross Salary: %.2f\n", employees[i].basic_salary);
    }

    return 0;
}
