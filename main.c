
#include "railway_main.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

int main()
{

    FILE *fptr;
    fptr = fopen("users.txt", "w");
    int isExists = fptr == NULL ? 0 : 1;
    createTextFile(isExists);
    fclose(fptr);

    int len = sizeof(users) / sizeof(users[0]);
    int res = IntroMenu(users, len);
    if (res)
    {
        system("cls");
        fptr = fopen("currentuser.txt", "w");
        fprintf(fptr, "type : %s", users[res - 1]);
        fclose(fptr);
        Authentication();
    }
}