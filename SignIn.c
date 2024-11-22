#include<stdio.h>
#include "railway_main.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct userCredential{
    char C_username[20];
    char C_pwd[7];
} u;

int SignIn(){
    printf("Enter the username : ");
    getchar();
    fgets(u.C_username, sizeof(u.C_username), stdin);
    u.C_username[strcspn(u.C_username, "\n")] = 0;


    printf("\nEnter the password : ");
    getchar();
    fgets(u.C_pwd, sizeof(u.C_pwd), stdin);
    u.C_pwd[strcspn(u.C_pwd, "\n")] = 0;


    printf("\nValidating.....!");
    Sleep(2000);
    
}
