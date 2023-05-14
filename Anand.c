
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[100];
    int age;
    float marks;
};

void addStudent(struct Student *students, int *count) {
    if (*count >= 100) {
        printf("Student database is full. Cannot add more students.\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student details:\n");
    printf("Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Age: ");
    scanf("%d", &newStudent.age);
    printf("Marks: ");
    scanf("%f", &newStudent.marks);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully.\n");
}

void updateStudent(struct Student *students, int count) {
    int rollNumber;
    int found = 0;

    printf("Enter the roll number to update: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new details for the student:\n");
            printf("Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Age: ");
            scanf("%d", &students[i].age);
            printf("Marks: ");
            scanf("%f", &students[i].marks);

            printf("Student details updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void deleteStudent(struct Student *students, int *count) {
    int rollNumber;
    int found = 0;

    printf("Enter the roll number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void displayStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("Student database is empty.\n");
        return;
    }

    printf("Student Database:\n");
    printf("Roll Number\tName\tAge\tMarks\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t%d\t%.2f\n", students[i].rollNumber, students[i].name, students[i].age, students[i].marks);
    }
}

int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    printf("Student Management System\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add a student\n");
        printf("2. Update a student\n");
        printf("3. Delete a student\n");
        printf("4. Display students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1



















