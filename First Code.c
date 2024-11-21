//working on login portal 
#include <stdio.h>
#include <string.h>
struct userinformation{
    char Fullname[50];
    char email[50];
    char password[30];
    char username[50];
    char phonenumber[20]
};

void userinput(char input[50])
{
    fgets(input, 50, stdin);
    input[strlen(input) - 1] = 0;
}

void generatingusername(char email[50], char username[50])
{
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] = '@')
        {
            break;
        }
        else if (email[i] != '@')
        {
            username[i] = email[i];
        } 
    }
}

int main()
{
    printf("\n------------Welcome to the login portal of Railway Managemnet System--------------");
    printf("\nSelect the option from the given menu");
    printf("\nPress 1 to Sign up");
    printf("\nPress 1 to Login the application");
    printf("\nPress 2 to Exit the applicaton");
    int useroption;
    printf("\nEnter your choice: ");
    scanf("%d", &useroption);
    return 0;
}