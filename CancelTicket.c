#include <stdio.h>
#include <string.h>
#include "railway_main.h"
#include <windows.h>


void CancelTicket()
{
    ShowUsersBookedTicket();

    FILE *fptr, *tempFile, *user;
    user = fopen("txtFiles/currentuser.txt", "r");
    char str[20];
    int ID, userID;
    while (fgets(str, sizeof(str), user))
    {
        sscanf(str, "userID : %d", &ID);
    }
    fclose(user);

    fptr = fopen("txtFiles/users.txt", "r");
    tempFile = fopen("txtFiles/userTicketsTemp.txt", "w");

    int Ticket_ID, temp_Ticket_ID;

    printf("\n\nEnter Ticket ID, you intend to cancel:  ");
    scanf("%d", &Ticket_ID);

    Sleep(1000);
    printf("\nProcessing....!");
    system("cls");

    char tempLine[100], Found = 0, CanceledLine[100];

    while (fgets(tempLine, sizeof(tempLine), fptr))
    {
        sscanf(tempLine, "id : %d", &userID);

        if (userID == ID)
        {
            
                if (strstr(tempLine, "ID :"))
                {
                    sscanf(tempLine, "ID : %d", &temp_Ticket_ID);
                    if (temp_Ticket_ID == Ticket_ID)
                    {
                        snprintf(CanceledLine, sizeof(CanceledLine), tempLine);
                        printf("\n%d Ticket has been cancelled!", Ticket_ID);
                        Found = 1;
                    }
                    else
                    {
                        fprintf(tempFile, "%s", tempLine);
                    }
                }
                else
                {
                    fprintf(tempFile, "%s", tempLine);
                }
            }
        else
        {
            fprintf(tempFile, "%s", tempLine);
        }
    }

    fclose(fptr);
    fclose(tempFile);

    if (Found)
    {
        tempFile = NULL;
        remove("txtFiles/users.txt");
        rename("txtFiles/userTicketsTemp.txt", "txtFiles/users.txt");

        fptr = fopen("txtFiles/users.txt", "r");
        tempFile = fopen("txtFiles/userTicketsTemp.txt", "w");

        char tempLine[300];
        int insideBookedSection = 0;

        while (fgets(tempLine, sizeof(tempLine), fptr))
        {
            if (strstr(tempLine, "id :"))
            {
                int userID;
                sscanf(tempLine, "id : %d", &userID);

                if (userID == ID)
                {
                    fprintf(tempFile, "%s", tempLine);

                    while (fgets(tempLine, sizeof(tempLine), fptr))
                    {
                        if (strstr(tempLine, "Cancelled :"))
                        {
                            insideBookedSection = 1;
                            fprintf(tempFile, "%s", tempLine);
                            break;
                        }
                        else
                        {
                            fprintf(tempFile, "%s", tempLine);
                        }
                    }

                    if (insideBookedSection)
                    {
                        fprintf(tempFile, "%s", CanceledLine);
                        while (fgets(tempLine, sizeof(tempLine), fptr))
                        {
                            fprintf(tempFile, "%s", tempLine);
                        }
                    }
                }
                else
                {
                    fprintf(tempFile, "%s", tempLine);
                }
            }
            else
            {
                fprintf(tempFile, "%s", tempLine);
            }
        }

        fclose(fptr);
        fclose(tempFile);

        remove("txtFiles/users.txt");
        rename("txtFiles/userTicketsTemp.txt", "txtFiles/users.txt");
    }
    else
    {
        printf("\n\nTicket ID not Found!");
        remove("txtFiles/userTicketsTemp.txt");
    }

    printf("\n\nEnter Any Key to Go Back...!");
    getchar();
    getchar();
    system("cls");
    Home();
}