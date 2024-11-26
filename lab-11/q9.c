#include <stdio.h>

#define MAX_DEPARTMENTS 3
#define MAX_COURSES 5
#define MAX_STUDENTS 10

struct Student {
    char name[50];
    int rollNo;
};

struct Instructor {
    char name[50];
};

struct Course {
    char courseName[50];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int studentCount;
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
        printf("Cannot add more departments.\n");
        return;
    }

    printf("Enter department name: ");
    scanf(" %[^\n]", departments[departmentCount].departmentName);
    departments[departmentCount].courseCount = 0;
    departmentCount++;
}

void addCourse() {
    if (departmentCount == 0) {
        printf("Add a department first.\n");
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
        printf("Cannot add more courses to this department.\n");
        return;
    }

    struct Course *course = &dept->courses[dept->courseCount];
    printf("Enter course name: ");
    scanf(" %[^\n]", course->courseName);
    printf("Enter instructor name: ");
    scanf(" %[^\n]", course->instructor.name);
    course->studentCount = 0;
    dept->courseCount++;
}

void addStudent() {
    if (departmentCount == 0) {
        printf("Add a department first.\n");
        return;
    }

    int deptIndex, courseIndex;
    printf("Enter department index (0 to %d): ", departmentCount - 1);
    scanf("%d", &deptIndex);

    if (deptIndex < 0 || deptIndex >= departmentCount) {
        printf("Invalid department index.\n");
        return;
    }

    struct Department *dept = &departments[deptIndex];
    printf("Enter course index (0 to %d): ", dept->courseCount - 1);
    scanf("%d", &courseIndex);

    if (courseIndex < 0 || courseIndex >= dept->courseCount) {
        printf("Invalid course index.\n");
        return;
    }

    struct Course *course = &dept->courses[courseIndex];
    if (course->studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students to this course.\n");
        return;
    }

    struct Student *student = &course->students[course->studentCount];
    printf("Enter student name: ");
    scanf(" %[^\n]", student->name);
    printf("Enter student roll number: ");
    scanf("%d", &student->rollNo);
    course->studentCount++;
}

void viewData() {
    for (int i = 0; i < departmentCount; i++) {
        printf("\nDepartment: %s\n", departments[i].departmentName);
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course *course = &departments[i].courses[j];
            printf("  Course: %s, Instructor: %s\n", course->courseName, course->instructor.name);
            for (int k = 0; k < course->studentCount; k++) {
                struct Student *student = &course->students[k];
                printf("    Student: %s, Roll No: %d\n", student->name, student->rollNo);
            }
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Add Student\n");
        printf("4. View Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) addDepartment();
        else if (choice == 2) addCourse();
        else if (choice == 3) addStudent();
        else if (choice == 4) viewData();
    } while (choice != 5);

    return 0;
}
