#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float salary;
} Employee;

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Maximum employee limit reached.\n");
        return;
    }
    Employee newEmployee;
    printf("Enter Employee Salary: ");
    scanf("%f", &newEmployee.salary);
    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Enter Employee Name: ");
    scanf("%s", newEmployee.name);
    employees[*count] = newEmployee;
    (*count)++;
    printf("Employee added successfully.\n");
}

void deleteEmployee(Employee employees[], int *count) {
    if (*count == 0) {
        printf("No employees to delete.\n");
        return;
    }
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Salary: %.2f, ID: %d, Name: %s\n", employees[i].salary, employees[i].id, employees[i].name);
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Display Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                deleteEmployee(employees, &count);
                break;
            case 3:
                displayEmployees(employees, count);
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
