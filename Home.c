#include <stdio.h>
#include "railway_main.h"
#include <string.h>
#include <windows.h>

void Home()
{
    FILE *fptr;
    fptr = fopen("txtFiles/currentuser.txt", "r");
    char str[20];
    char type[7];
    fgets(str, 20, fptr);
    sscanf(str, "type : %s", type);
    fclose(fptr);
    // printf("%d", strlen(type));
    int admin = strlen(type) == 5 ? 1 : 0;

    int len = admin ? (sizeof(admin_arr) / sizeof(admin_arr[0])) : (sizeof(user_arr) / sizeof(user_arr[0]));
    int res = admin ? IntroMenu(admin_arr, len) : IntroMenu(user_arr, len);

    if (res == len)
    {
        Logout();
    }
    else if (res == 1)
    {
        Sleep(1000);
        system("cls");
        ViewTrains();
        printf("\n\nEnter Any Key to Go Back...!");
        getchar();
        getchar();
        system("cls");
        Home();
    }
    else if (res == 2 && !admin)
    {
        Sleep(1000);
        system("cls");
        BookTicket();
    }
    else if (res == 3 && !admin)
    {
        Sleep(1000);
        system("cls");
        CancelTicket();
        }
    else if (res == 4 && !admin)
    {
        Sleep(1000);
        system("cls");
        ShowUsersBookedTicket();
        printf("\n\nEnter Any Key to Go Back...!");
        getchar();
        getchar();
        system("cls");
        Home();
    }
    else if (res == 5 && !admin)
    {
        Sleep(1000);
        system("cls");
        ShowUsersCancelledTicket();
        printf("\n\nEnter Any Key to Go Back...!");
        getchar();
        getchar();
        system("cls");
        Home();
    }
}