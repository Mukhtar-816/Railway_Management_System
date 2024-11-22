
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
    printf("Enter Username: ");
    getchar();
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = 0;

    printf("\nEnter Gender(M/F): ");
    scanf("%c", &user.gender);

    printf("\nCreate Password (6 character long): ");
    getchar();
    fgets(user.pwd, sizeof(user.pwd), stdin);
    user.pwd[strcspn(user.username, "\n")] = 0;

    printf("\nPlease Wait...........................!");
    Sleep(2000);

    if (strlen(user.username) !=0 && (user.gender == 'M' || user.gender == 'F') && strlen(user.pwd) == 6)
    {
        fptr = fopen("users.txt", "a");
        fprintf(fptr, "\n\nusername : %s \ngender : %c \npassword : %s",  user.username, user.gender, user.pwd);
        fclose(fptr);
        printf("\nUser Successfully Created.");
        Sleep(1000);
        system("cls");
        Authentication();
    }
    else
    {
        printf("\nInvalid inputs");
        Sleep(1000);
        system("cls");
        Authentication();
    }
}