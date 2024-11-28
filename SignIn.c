#include <stdio.h>
#include "railway_main.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct userCredential
{
    char C_username[20];
    char C_pwd[7];
} user;

void SignIn()
{
    printf("Enter the username : ");
    getchar();
    fgets(user.C_username, sizeof(user.C_username), stdin);
    user.C_username[strcspn(user.C_username, "\n")] = 0;

    printf("\nEnter the password : ");
    scanf("%s", &user.C_pwd);

    printf("\nValidating.....!");
    Sleep(2000);

    if (user.C_username != NULL && strlen(user.C_pwd) <= 6 && user.C_pwd != NULL)
    {
        if (AuthValidator(user.C_username, user.C_pwd) == 1)
        {
            printf("\n\n===============< Login Successful! >===============");
            Sleep(1000);
            system("cls");
            Home();
        }
        else
        {
            printf("\n\n===============< Invalid Credentials >===============");
            Sleep(2000);
            system("cls");
            Authentication();
        }
    }

    else
    {
        printf("\nInvalid Inputs..!");
        Sleep(1000);
        system("cls");
    }
}
