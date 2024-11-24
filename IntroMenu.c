#include <stdio.h>
#include "railway_main.h"
#include <stdlib.h>
#include <string.h>

int IntroMenu(const char arr[][20], int len)
{

    int res;

    printf("\n\n\n*****************************************************************************\n");
    printf("*                                                                           *\n");
    printf("*                         Railway Management System                         *\n");
    printf("*                                                                           *\n");
    printf("*****************************************************************************\n");

    printf("\nSelect an option :-\n");
    for (int i = 0; i < len; i++)
    {
        printf("\n%d. %s", i + 1, arr[i]);
    }

    printf("\n\nEnter Choice : ");
    scanf("%d", &res);
    if (res > len || res <= 0 && strcmp(arr[res - 1], "Exit") != 0)
    {
        char mes[20] = "\nInvalid Option";
        Invalid_Error(mes);
    }
    else if (res == len && strcmp(arr[res - 1], "Logout") == 0)
    {
        Logout();
    }
    else if (res == len && strcmp(arr[res - 1], "Quit") == 0)
    {
        system("cls");
        InitiatingCall();
    }
    else if (res == len && strcmp(arr[res - 1], "Exit") == 0)
    {
        return 0;
        exit;
    }
    else
    {
        return res;
    }
};