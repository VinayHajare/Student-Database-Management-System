/*
Project Title :- Student Database Management System
Language Used :- C
IDE Used      :- Code::Blocks and Visual Studio Code
Platform Used :- Windows 64-bit Architecture.
Created By    :- Hajare Vinay
                 Dangi Niranjan
                 Gorde Shubham
*/
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

// Variable to keep track of number of student
int i = 0;

// Structure to store student information
struct student
{
    char fname[50];
    char lname[50];
    long int enroll;
    char branch[50];
    char division[50];
    int dob;
    int age;
    int contact;
} st[55];

/*-------Containing all the prototypes...*/

void add_student();
void find_student();
void delete_student(int n);
void list_student(int n);
void modify_student();
void total_student();

// Driver code
void main()
{
    int key, n;
    system("cls");
    int choice;
    printf("\n----Welcome to Student Database Management System----\n");
    while (i = 1)
    {
        SetConsoleTitle(" Student Database Management System ");
        printf("<<<< Loading Please Wait >>>>");
        for (int i = 0; i < 5; i++)
        {
            printf("\t(*_*)");
            sleep(3);
        }
        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
        printf("\n\n\t\t\t\t\t     *                    *");
        printf("\n\n\t\t\t\t\t     *       Welcome      *");
        printf("\n\n\t\t\t\t\t     *                    *");
        printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
        printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
        scanf("%d", &key);
        system("cls");
        printf("\t\t\t\t\t\t\t\tMenu\n");
        printf("\n\n\t1.Add Student Record\n");
        printf("\t2. Find Student Record\n");
        printf("\t3. Delete Student Record\n");
        printf("\t4. List All Student Record\n");
        printf("\t5. Modify Student Record\n");
        printf("\t6. Show Total Number of Student Record\n");
        printf("\t7. Exit From System\n");
        printf("\n\n\tEnter Your Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter how many students do you want\n");
            scanf("%d", &n); // This n transfers the number of students user wants.
            add_student(n);
            break;
        case 2:
            find_student(n);
            break;
        case 3:
            delete_student(n);
            break;
        case 4:
            list_student(n);
            break;
        case 5:
            modify_student();
            break;
        case 6:
            total_student(n);
            break;
        case 7:
            exit(0);
            break;
        }
    }
}

void add_student(int n) // This function is used to add the record of student.
{

    for (int i = 0; i < n; i++) // Entering Student's Information of n students.
    {
        printf("Enter Student %d first name\t\t", i + 1);
        printf("\n");
        scanf("%s", &st[i].fname);

        printf("Enter Student %d last name \t\t", i + 1);
        printf("\n");
        scanf("%s", &st[i].lname);

        printf("Enter Student %d Enrollment No:\t ", i + 1);
        printf("\n");
        scanf("%ld", &st[i].enroll);

        printf("Enter Student %d Branch: \t", i + 1);
        printf("\n");
        scanf("%s", &st[i].branch);

        printf("Enter Student %d Section :\t", i + 1);
        printf("\n");
        scanf("%s", &st[i].division);

        printf("Enter Student %d DOB( Enter continous  instead of /)\t\t", i + 1);
        printf("\n");
        scanf("%d", &st[i].dob); // This needs to be checked.

        printf("Enter Student %d Age :\t\t", i + 1);
        printf("\n");
        scanf("%d", &st[i].age);

        printf("Enter Student %d Contact No: \t\t ", i + 1);
        printf("\n");
        scanf("%d", &st[i].contact);

        for (int i = 0; i < 40; i++)
        {
            printf("%c", ' _'); // Printing some amount of spaces
        }
        printf("\n");
    }

    printf("\nStudents's Information Added Successfully\n");
}
void find_student(int n)
{
    int enroll;
    int m; // local variable
    int flag = 0;
    printf("Enter the Enrollment no you want to Search\n");
    scanf("%d", &enroll);

    for (m = 0; m < n; m++)
    {
        if (enroll == st[m].enroll)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Record Found at %d location in the database.\n", m + 1);
    }
    else
    {
        printf("Record Not Found\n");
    }
}
void delete_student(int n)
{
    system("cls");
    int a;
    printf("Enter the Enrollment No. of Student Which You Want To Delete:\n");
    scanf("%d", &a);
    for (int j = 0; j <= n; j++)
    {
        if (a == st[j].enroll)
        {
            for (int k = j; k < 49; k++)
            {
                st[k] = st[k + 1];
                i--;
            }
        }
    }

    printf("The Enrollment number is removed successfully.");
}
void list_student(int n) // This function list all students in the system.
{
    printf("Student List :-\n");
    for (int j = 0; j < n; j++)
    {
        printf("\tName:- %s %s Branch:- %s section:- %s\n", st[j].fname, st[j].lname, st[j].branch, st[j].division);
    }
}

void modify_student() // This function modify the record of the students.
{
    int a;
    int z;
    printf("Enter the Enrollment No. of the student which you want to update :-\n");
    scanf("%d", &a);
    for (int j = 0; j <= i; j++)
    {
        if (a == st[j].enroll)
        {
            printf(" 1. First Name:\n");
            printf(" 2. Last Name :\n");
            printf(" 3. Enrollment No.:\n");
            printf(" 4. Branch :\n");
            printf(" 5. Division:\n");
            printf(" 6. Date of birth:\n");
            printf(" 7. Contact No.:\n");
            printf(" 8. Age:\n");

            printf("Enter your choice :-");
            scanf("%d", &z);
            switch (z)
            {
            case 1:
                printf("Enter the new first name:");
                scanf("%s", &st[j].fname);
                break;

            case 2:
                printf("Enter the new last name:");
                scanf("%s", &st[j].lname);
                break;

            case 3:
                printf("Enter new enrollment number :");
                scanf("%d", &st[j].enroll);
                break;

            case 4:
                printf("Enter new Branch :");
                scanf("%s", &st[j].branch);
                break;

            case 5:
                printf("Enter new section / Division: ");
                scanf("%s", &st[j].division);
                break;

            case 6:
                printf("Enter new Date of  Birth :");
                scanf("%d", &st[j].dob);
                break;

            case 7:
                printf("Enter new contact :");
                scanf("%d", &st[j].contact);
                break;

            case 8:
                printf("Enter new age :");
                scanf("%d", &st[j].age);
                break;
            }

            printf(" Updated Successfully !!!\n");
        }
    }
}
void total_student(int num) // This function display total number of students in the system.
{
    printf("\tThe total number of Student are %d\n", num);
    printf("---------------------------------------");
    printf("\n\tYou can have a max of 50 students\n");
    printf("\n\tYou can have %d more students\n", 50 - num);
}
