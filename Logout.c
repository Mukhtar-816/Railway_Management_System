#include <stdio.h>
#include <windows.h>
#include "railway_main.h"

void Logout()
{
    printf("\n=====================< Logging Out >=====================");
    Sleep(1000);
    remove("txtFiles/currentuser.txt");
    system("cls");
    Authentication();
}