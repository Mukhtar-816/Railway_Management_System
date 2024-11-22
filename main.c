
#include "railway_main.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

int main()
{

    FILE *fptr;
    fptr = fopen("users.txt", "r");
    int isExists = fptr == NULL ? 0 : 1;
    createTextFile(isExists);

    int len = sizeof(users) / sizeof(users[0]);
    int res = IntroMenu(users, len);
    if (res)
    {
        system("cls");
        Authentication();
    }
}