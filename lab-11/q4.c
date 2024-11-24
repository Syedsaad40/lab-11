#include<stdio.h>
#include<string.h>


typedef struct employee {
    char Name[50];
    char DOB[30];
    int EmpID;
    char Department[40];
    float Salary;
} Employee;

Employee employees[50];
int employeeCount = 0;


void display() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%s\t%s\t%s\t%.2f\n",
               employees[i].EmpID,
               employees[i].Name,
               employees[i].DOB,
               employees[i].Department,
               employees[i].Salary);
    }
}


void delete_employee() {
    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].EmpID == id) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Error: Employee with ID %d not found.\n", id);
    }
}
void add() {
    printf("Enter Name: ");
    scanf(" %[^\n]s", employees[employeeCount].Name);

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf(" %[^\n]s", employees[employeeCount].DOB);

    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].EmpID);

    printf("Enter Department: ");
    scanf(" %[^\n]s", employees[employeeCount].Department);

    printf("Enter Salary: ");
    scanf("%f", &employees[employeeCount].Salary);

    employeeCount++;
    printf("Employee added successfully!\n");
}
int main(void) {
    int choice;
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                delete_employee();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
