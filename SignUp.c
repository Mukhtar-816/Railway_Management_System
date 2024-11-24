
#include <stdio.h>
#include "railway_main.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct user_arr
{
    char username[20];
    char gender;
    char pwd[7];
} user;



int checkUniqueID(int newID) {
    FILE *fptr;
    char line[100];
    fptr = fopen("txtFiles/users.txt", "r");

    if (fptr == NULL) {
        return 1;  
    }

    while (fgets(line, sizeof(line), fptr)) {
        int id;
        if (sscanf(line, "id : %d", &id) == 1) {
            if (id == newID) {
                fclose(fptr);
                return 0;  
            }
        }
    }

    fclose(fptr);
    return 1;  
};



void SignUp()
{
    FILE *fptr;
    int valid = 0;
    fptr = fopen("txtFiles/currentuser.txt", "r");
    char str[20];
    char type[7];
    fgets(str, 20, fptr);
    sscanf(str, "type : %s", type);
    fclose(fptr);
    while (!valid)
    {
        printf("Enter Username (max 6 characters): ");
        getchar();
        fgets(user.username, sizeof(user.username), stdin);
        user.username[strcspn(user.username, "\n")] = '\0';

        // printf("\nEnter Gender(M/F): ");
        // user.gender = getchar();
        // getchar();

        printf("\nCreate Password (6 character long): ");
        scanf("%s", &user.pwd);

        printf("\nPlease Wait...........................!");
        Sleep(2000);

        if (strlen(user.username) != 0 /*(user.gender == 'M' || user.gender == 'F' || user.gender == 'm' || user.gender == 'f')*/ && strlen(user.pwd) == 6)
        {
            int uniqueID = 0;
            int newID;

            while (!uniqueID) {
                newID = generateRandomID();
                uniqueID = checkUniqueID(newID);  
            }


            fptr = strlen(type) == 5 ? fopen("txtFiles/admins.txt", "a") : fopen("txtFiles/users.txt", "a");

            fprintf(fptr, "id : %d\n", newID);
            fprintf(fptr, "username : %s\n", user.username);
            fprintf(fptr, "password : %s\n", user.pwd);
            fprintf(fptr, "Booked : \n");      
            fprintf(fptr, "Cancelled : \n"); 
            fprintf(fptr, "\n");  

            fclose(fptr);
            printf("\n\nUser Successfully Created.");
            Sleep(1000);
            system("cls");
            Authentication();
            valid = 1;
        }
        else
        {
            printf("\nInvalid Inputs..!");
            Sleep(1000);
            system("cls");
        }
    }
}