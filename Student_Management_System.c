#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Add Student
void addStudent()
{
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;

    printf("\nStudent Added Successfully!\n");
}

// Display Students
void displayStudents()
{
    int i;

    if (count == 0)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n----- Student Records -----\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRoll Number : %d", s[i].roll);
        printf("\nName        : %s", s[i].name);
        printf("\nMarks       : %.2f\n", s[i].marks);
    }
}

// Search Student
void searchStudent()
{
    int roll, i;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", s[i].roll);
            printf("Name        : %s\n", s[i].name);
            printf("Marks       : %.2f\n", s[i].marks);
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Update Student
void updateStudent()
{
    int roll, i;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf("%s", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("\nRecord Updated Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Delete Student
void deleteStudent()
{
    int roll, i, j;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            for (j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            count--;
            printf("\nStudent Deleted Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Save to File
void saveToFile()
{
    FILE *fp = fopen("students.txt", "w");

    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%d %s %.2f\n",
                s[i].roll,
                s[i].name,
                s[i].marks);
    }

    fclose(fp);

    printf("\nData Saved Successfully!\n");
}

// Load from File
void loadFromFile()
{
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    count = 0;

    while (fscanf(fp, "%d %s %f",
                  &s[count].roll,
                  s[count].name,
                  &s[count].marks) != EOF)
    {
        count++;
    }

    fclose(fp);
}

int main()
{
    int choice;

    loadFromFile();

    do
    {
        printf("\n\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Save Data\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            saveToFile();
            break;

        case 7:
            saveToFile();
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}