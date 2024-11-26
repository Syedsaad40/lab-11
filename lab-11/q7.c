#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 3
#define MAX_COURSES 5

struct Course {
    char courseID[10];
    char courseName[50];
    int credits;
};

struct Department {
    char departmentName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

struct Department departments[MAX_DEPARTMENTS];
int departmentCount = 0;

void addDepartment() {
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("No more departments can be added.\n");
        return;
    }

    printf("Enter department name: ");
    scanf(" %[^\n]", departments[departmentCount].departmentName);
    departments[departmentCount].courseCount = 0;
    departmentCount++;
}

void addCourse() {
    if (departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    int deptIndex;
    printf("Enter department index (0 to %d): ", departmentCount - 1);
    scanf("%d", &deptIndex);

    if (deptIndex < 0 || deptIndex >= departmentCount) {
        printf("Invalid department index.\n");
        return;
    }

    struct Department *dept = &departments[deptIndex];
    if (dept->courseCount >= MAX_COURSES) {
        printf("No more courses can be added to this department.\n");
        return;
    }

    struct Course *course = &dept->courses[dept->courseCount];
    printf("Enter course ID: ");
    scanf(" %[^\n]", course->courseID);
    printf("Enter course name: ");
    scanf(" %[^\n]", course->courseName);
    printf("Enter credits: ");
    scanf("%d", &course->credits);

    dept->courseCount++;
}

void displayDetails() {
    for (int i = 0; i < departmentCount; i++) {
        printf("Department: %s\n", departments[i].departmentName);
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course *course = &departments[i].courses[j];
            printf("  Course ID: %s, Name: %s, Credits: %d\n", course->courseID, course->courseName, course->credits);
        }
    }
}

void calculateTotalCredits() {
    for (int i = 0; i < departmentCount; i++) {
        int totalCredits = 0;
        for (int j = 0; j < departments[i].courseCount; j++) {
            totalCredits += departments[i].courses[j].credits;
        }
        printf("Total credits for %s: %d\n", departments[i].departmentName, totalCredits);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Display Details\n");
        printf("4. Calculate Total Credits\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) addDepartment();
        else if (choice == 2) addCourse();
        else if (choice == 3) displayDetails();
        else if (choice == 4) calculateTotalCredits();
    } while (choice != 5);

    return 0;
}
