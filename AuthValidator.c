#include <stdio.h>
#include <string.h>
#include "railway_main.h"
#include <windows.h>

int AuthValidator(char username[], char pwd[])
{
    FILE *fptr;
    fptr = fopen("txtFiles/currentuser.txt", "r");
    char str[20];
    char type[7];
    fgets(str, 20, fptr);
    sscanf(str, "type : %s", type);
    fclose(fptr);
    fptr = strlen(type) == 5 ? fopen("txtFiles/admins.txt", "r") : fopen("txtFiles/users.txt", "r");
    char tempLine[100];
    int ID, unID = 0;

    while (fgets(tempLine, sizeof(tempLine), fptr))
    {
        sscanf(tempLine, "id : %d", &ID);

        if (strstr(tempLine, "username :"))
        {
            char fileUsername[20], filePassword[7];
            sscanf(tempLine, "username : %s", fileUsername);

            if (strcmp(fileUsername, username) == 0)
            {
                fgets(tempLine, sizeof(tempLine), fptr);
                sscanf(tempLine, "password : %s", filePassword);

                if (strcmp(filePassword, pwd) == 0)
                {
                    fclose(fptr);
                    unID = ID;

                    fptr = fopen("txtFiles/currentuser.txt", "a");

                    fprintf(fptr, "\nuserID : %d\n", unID);
                    fclose(fptr);
                    return 1;
                }
            }
        }
    }
}