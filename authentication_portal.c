//working on login portal structure.
//Converted password into unreadable form
// Added password authentication
//Generated username form the email address
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define Enter 13
#define Backspace 8


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

void takepassword(char pwd[50])
{
    int i = 0;
    char ch;
    while(1)
    {
        ch = getch();
        if (ch == Enter)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == Backspace)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

char generateUsername(char email[50], char username[50])
{
    int i;
    for (i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            username[i] = email[i];
        } 
    }
    username[i] = '\0';
}

int main()
{
    char password2[50];
    FILE *fp;
    int correctuser = 0;
    printf("\n------------Welcome to the application of Railway Managemnet System--------------");
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
        {
            printf("\nEnter your Full Name:  ");
            takeinput(person.fullName);
            printf("\nEnter your email address:  ");
            takeinput(person.email);
            printf("\nEnter your phone number:  ");
            takeinput(person.phone);
            printf("\nEnter your password:  ");
            takepassword(person.password);
            //printf("%s", person.password);
            printf("\nConfirm your password:  ");
            takepassword(password2);
            
            //Matching the usergiven password
            if (!strcmp (person.password, password2))
            {
                printf("\n\nYour password matched.");
                generateUsername(person.email, person.username);
                fp = fopen("Users.txt", "a+");
                if (fp == NULL)
                {
                    printf("\n\nError opening the file for saving information.");
                    return 1;
                }
                //fwrite(&person,sizeof(struct userinformation), 1, fp);
                
                fprintf(fp, "%s\t%s\t%s\t%s\t%s\n",
                person.fullName, person.email, person.phone, person.password, person.username);
                
                /*if (fwrite != 0)
                {
                    printf("\n\nUser registration is successful, Your user name is %s", person.username);
                }
                else
                {
                    printf("\n\nSorry something went wrong.");
                }*/
                fclose(fp);
            }
            else
            {
                printf("\n\nYour password donot matched.");
            }
            break;
        }

        case 2:
        {
            char username[50], password[50];
            int correctuser = 0;
            struct userinformation person;
            
            printf("\nEnter your username: ");
            takeinput(username);
            printf("\nEnter your password: ");
            takepassword(password);

            fp = fopen("Users.txt", "r");

            if (fp == NULL) {
                printf("\n\nError opening the file.");
                break;
            }
            
            //while (fread(&person, sizeof (struct userinformation), 1, fp))
            
            while (fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
                          person.fullName, person.email, person.phone, person.password, person.username) != EOF)
            {
                if (!strcmp(person.username, username))
                {
                    if (!strcmp(person.password, password))
                    {
                        printf("\n\t\t\t\t\tWelcome %s", person.fullName);
                        printf("\n\nFull Name:\t%s", person.fullName);
                        printf("\nEmail:\t\t%s", person.email);
                        printf("\nUsername:\t%s", person.username);
                        printf("\nContact no:\t%s", person.phone);
                        correctuser = 1;
                        break;
                    }
                    else
                    {
                        printf("\n\nInvalid Password.");
                        correctuser = 1;
                        break;
                    }
                }    
            }
            fclose(fp);

            if (!correctuser)
                {
                    printf("\n\nUser is not registered.");
                }
            break;
        }
        case 3:
        {
            printf("\t\t\t\tGood Bye.");
            return 0;
        }
        default:
        {
            printf("Invalid option, Please select the correct option.");
        }
    }
    return 0;
}