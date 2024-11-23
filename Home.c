#include <stdio.h>
#include "railway_main.h"
#include <string.h>
#include <windows.h>

int Home()
{
    int len = sizeof(user_arr) / sizeof(user_arr[0]);
    int res = IntroMenu(user_arr, len);

    if (res == 6){
        printf("\n=====================< Logging Out >=====================");
        Sleep(1000);
        remove("currentuser.txt");
        system("cls");
        Authentication();
    }

    
}