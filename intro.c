#include <stdio.h>
#include "railway_main.h"
#include <stdlib.h>

int IntroMenu(const char arr[][20], int len)
{

    int res;

    printf("\n****************************Railway Management System****************************\n");

    printf("\nSelect an option :-");
    for (int i = 0; i < len; i++)
    {
        printf("\n%d. %s", i + 1, arr[i]);
    }

    printf("\n\nEnter Choice : ");
    scanf("%d", &res);
    if (res > len || res <= 0)
    {
        char mes[20] = "\nInvalid Option";
        Invalid_Error(mes);
    }
    else if (res == len)
    {
        exit;
    }
    else
    {
        return res;
    }
};