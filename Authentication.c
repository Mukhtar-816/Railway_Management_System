#include <stdio.h>
#include "railway_main.h"
#include <windows.h>

int Authentication()
{
    FILE *fptr;
    fptr = fopen("users.txt", "r");
    fptr == NULL ? fptr = fopen("users.txt", "w") : 0;
    fclose(fptr);

    fptr = fopen("admins.txt", "r");
    fptr == NULL ? fptr = fopen("admins.txt", "w") : 0;
    fclose(fptr);

    int len = sizeof(authentication_arr) / sizeof(user_arr[0]); // Get the number of elements in User_arr
    int res = IntroMenu(authentication_arr, len);
    if (res == 1)
    {
        system("cls");
        SignIn();
    }
    else if (res == 2)
    {
        system("cls");
        SignUp();
    }
    else if (res == 3)
    {
        exit;
        remove("currentuser.txt");
    }
    else
    {
        char msg[20] = "Invalid Input";
        Invalid_Error(msg);
    }
}
