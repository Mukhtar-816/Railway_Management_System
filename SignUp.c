
#include <stdio.h>
#include "railway_main.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define Enter 13
#define Backspace 8

struct user_arr
{
    char username[50];
    char email[50];
    char password[50];
} user;

void takeinput(char input[50])
{
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
}

void takepassword(char pwd[50])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == Enter)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == Backspace)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

int checkUniqueID(int newID)
{
    FILE *fptr;
    char line[100];
    fptr = fopen("txtFiles/users.txt", "r");

    if (fptr == NULL)
    {
        return 1;
    }

    while (fgets(line, sizeof(line), fptr))
    {
        int id;
        if (sscanf(line, "id : %d", &id) == 1)
        {
            if (id == newID)
            {
                fclose(fptr);
                return 0;
            }
        }
    }

    fclose(fptr);
    return 1;
};

void SignUp()
{
    FILE *fptr;
    int valid = 0;
    fptr = fopen("txtFiles/currentuser.txt", "r");
    char str[20];
    char type[7];
    char password2[50];
    fgets(str, 20, fptr);
    sscanf(str, "type : %s", type);
    fclose(fptr);
    while (!valid)
    {
        printf("Enter your username : ");
        getchar();
        fgets(user.username, sizeof(user.username), stdin);
        user.username[strcspn(user.username, "\n")] = 0;

        printf("\nEnter your email address:  ");
        takeinput(user.email);
        printf("\nEnter your password:  ");
        takepassword(user.password);
        // printf("%s", user.password);
        printf("\n\nConfirm your password:  ");
        takepassword(password2);

        printf("\n\n\nPlease Wait...........................!");
        Sleep(2000);

        if (strstr(type, "Admin"))
        {
            if (strlen(user.username) != 0 && strlen(password2) != 0 && strlen(user.password) != 0)
            {
                if (!strcmp(user.password, password2))
                {
                    printf("\n\nYour password matched.");
                    int uniqueID = 0;
                    int newID;

                    while (!uniqueID)
                    {
                        newID = generateRandomID(0);
                        uniqueID = checkUniqueID(newID);
                    }

                    fptr = fopen("txtFiles/admins.txt", "a");

                    if (fptr == NULL)
                    {
                        printf("\n\nError opening the file for saving information.");
                    }

                    fprintf(fptr, "id : %d\n", newID);
                    fprintf(fptr, "username : %s\n", user.username);
                    fprintf(fptr, "password : %s\n", user.password);
                    fprintf(fptr, "email : %s\n", user.email);
                    fprintf(fptr, "AddedTrains :\n");
                    fprintf(fptr, "RemovedTrains :\n");
                    fprintf(fptr, "\n");

                    fclose(fptr);
                    printf("\n\nAdmin Created Successfully.");
                    Sleep(1000);
                    system("cls");
                    Authentication();
                    valid = 1;
                }
                else
                {
                    printf("\n\nYour password donot matched.");
                    Sleep(1000);
                    system("cls");
                }
            }
            else
            {
                printf("\nInvalid Inputs..!");
                Sleep(1000);
                system("cls");
            }
        }
        else if (strstr(type, "User"))
        {
            if (strlen(user.username) != 0 && strlen(password2) != 0 && strlen(user.password) != 0)
            {
                if (!strcmp(user.password, password2))
                {
                    printf("\n\nYour password matched.");
                    int uniqueID = 0;
                    int newID;

                    while (!uniqueID)
                    {
                        newID = generateRandomID(0);
                        uniqueID = checkUniqueID(newID);
                    }

                    fptr = fopen("txtFiles/users.txt", "a");

                    if (fptr == NULL)
                    {
                        printf("\n\nError opening the file for saving information.");
                    }

                    fprintf(fptr, "id : %d\n", newID);
                    fprintf(fptr, "username : %s\n", user.username);
                    fprintf(fptr, "password : %s\n", user.password);
                    fprintf(fptr, "email : %s\n", user.email);
                    fprintf(fptr, "Booked :\n");
                    fprintf(fptr, "Cancelled :\n");
                    fprintf(fptr, "\n");

                    fclose(fptr);
                    printf("\n\nAdmin Created Successfully.");
                    Sleep(1000);
                    system("cls");
                    Authentication();
                    valid = 1;
                }
                else
                {
                    printf("\n\nYour password donot matched.");
                    Sleep(1000);
                    system("cls");
                }
            }
            else
            {
                printf("\nInvalid Inputs..!");
                Sleep(1000);
                system("cls");
            }
        }
    }
}