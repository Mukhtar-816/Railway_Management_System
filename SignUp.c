
#include <stdio.h>
#include "railway_main.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct user_arr
{
    char username[20];
    char gender;
    char pwd[7];
} user;

int SignUp()
{
    FILE *fptr;
    int valid = 0;
    while (!valid)
    {
        printf("Enter Username (max 6 characters): ");
        getchar();
        fgets(user.username, sizeof(user.username), stdin);
        user.username[strcspn(user.username, "\n")] = '\0';

        // printf("\nEnter Gender(M/F): ");
        // user.gender = getchar();
        // getchar();

        printf("\nCreate Password (6 character long): ");
        scanf("%s", &user.pwd);

        printf("\nPlease Wait...........................!");
        Sleep(2000);

        if (strlen(user.username) != 0 /*(user.gender == 'M' || user.gender == 'F' || user.gender == 'm' || user.gender == 'f')*/ && strlen(user.pwd) == 6)
        {
            fptr = fopen("users.txt", "a");
            fprintf(fptr, "username : %s password : %s\n", user.username, user.pwd);
            fclose(fptr);
            printf("\nUser Successfully Created.");
            Sleep(1000);
            system("cls");
            Authentication();
            valid = 1;
        }
        else
        {
            printf("\nInvalid Inputs..!");
            Sleep(1000);
            system("cls");
        }
    }
}