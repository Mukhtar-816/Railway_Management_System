#include <stdio.h>
#include "railway_main.h"
#include <string.h>
#include <windows.h>

int Home()
{
    FILE *fptr;
    fptr = fopen("currentuser.txt", "r");
    char str[20];
    char type[7];
    fgets(str, 20, fptr);
    sscanf(str, "type : %s", type);
    fclose(fptr);
    // printf("%d", strlen(type));

    int len = (strlen(type) == 5) ? (sizeof(admin_arr) / sizeof(admin_arr[0])) : (sizeof(user_arr) / sizeof(user_arr[0]));
    int res = (strlen(type) == 5) ? IntroMenu(admin_arr, len) : IntroMenu(user_arr, len);

    if (res == 6)
    {
        printf("\n=====================< Logging Out >=====================");
        Sleep(1000);
        remove("currentuser.txt");
        system("cls");
        Authentication();
    }
}