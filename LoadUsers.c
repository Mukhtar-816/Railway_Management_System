#include "railway_main.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>



const char _USERS[100][20];

int LoadUsers(){
    FILE *fptr;
    fptr = fopen("users.txt", "r");
        

        fclose(fptr);
}