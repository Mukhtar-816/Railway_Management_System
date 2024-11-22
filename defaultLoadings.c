#include <stdio.h>
#include "railway_main.h"

int createTextFile(int isExist)
{
    FILE *fptr;

    if (isExist == 1)
    {
        printf("File Already exits");
    }
    else
    {
        fptr = fopen("users.txt", "w");
        
    }
}