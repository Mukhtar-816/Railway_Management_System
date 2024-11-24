//working on login portal structure.
#include <stdio.h>
#include <string.h>

struct userinformation{
    char fullName[50];
    char email[50];
    char phone[50];
    char password[50];
    char username[50];
    
};

void takeinput(char input[50])
{
    fgets(input, 50, stdin);
    input[strlen(input) - 1] = 0;
}

char generateUsername(char email[50], char username[50])
{
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
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
    printf("\nPress 2 to Login the application");
    printf("\nPress 3 to Exit the applicaton");
    int userinput;
    printf("\nEnter your choice: ");
    scanf("%d", &userinput);
    fgetc(stdin);
    struct userinformation person;
    
    switch(userinput)
    {
        case 1:
            printf("\nEnter your Full Name:  ");
            takeinput(person.fullName);
            printf("\nEnter your email address:  ");
            takeinput(person.email);
            printf("\nEnter your phone number:  ");
            takeinput(person.phone);
            printf("\nEnter your password:  ");
            takeinput(person.password);
            
    }
    return 0;
}