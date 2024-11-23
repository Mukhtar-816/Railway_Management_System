#include <stdio.h>
#include <string.h>
#include "railway_main.h"
#include <windows.h>

int AuthValidator(char username[], char pwd[]){
    FILE *fptr;
    fptr = fopen("currentuser.txt", "r");
    char str[20];
    char type[7];
    fgets(str, 20, fptr);
    sscanf(str, "type : %s", type);
    fclose(fptr);
    fptr = strlen(type) == 5 ? fopen("admins.txt", "r") : fopen("users.txt", "r");
    char tempLine[100];
        char fileusername[20];
        char filepwd[7];
        while(fgets(tempLine, sizeof(tempLine), fptr)){
            if (sscanf(tempLine, "username : %s password : %s\n", fileusername, filepwd)){
                // printf("\n%s \n%s \n%s \n%s", username, pwd, fileusername, filepwd);
                if (strcmp(fileusername, username) == 0 && strcmp(filepwd, pwd) == 0){
                    return 1;
                }
            }
        }
}