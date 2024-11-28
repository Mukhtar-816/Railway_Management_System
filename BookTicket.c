#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "railway_main.h"

struct Ticket
{
    int Train_No;
    int TicketCost;
} T;

struct TempTicket
{
    int No;
    char Name[20];
    char From[20];
    char To[20];
    int Cost;
    char Time[10];
    int Slots;
} _T;

struct TempUser
{
    int id;
    char Name[20];
    char pwd[20];
} _U;

void BookTicket()
{
    FILE *fptr, *tempFile, *BookFile, *user, *tempUserFile;

    user = fopen("txtFiles/currentuser.txt", "r");
    char str[20];
    int ID;
    while (fgets(str, sizeof(str), user))
    {
        sscanf(str, "userID : %d", &ID);
    }
    fclose(user);

    fptr = fopen("txtFiles/trains_data.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening trains_data.txt file!\n");
        return;
    }

    tempFile = fopen("txtFiles/tempFile.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error creating tempFile.txt file!\n");
        fclose(fptr);
        return;
    }

    ViewTrains();

    printf("\n\nEnter Train No: ");
    scanf("%d", &T.Train_No);

    printf("\n\nPlease wait!, Ticket booking is in process....");
    Sleep(2000);

    char tempLine[100];
    int found = 0;
    int invalidTrainNo = 1;
    char updatedBooking[100];

    while (fgets(tempLine, sizeof(tempLine), fptr))
    {
        if (sscanf(tempLine, "No : %d Name : %s From : %s To : %s Cost : %d Time : %s Slots : %d",
                   &_T.No, _T.Name, _T.From, _T.To, &_T.Cost, _T.Time, &_T.Slots))
        {
            if (T.Train_No == _T.No)
            {
                invalidTrainNo = 0;
                if (_T.Slots > 0)
                {
                    _T.Slots -= 1;  
                    found = 1;
                    snprintf(updatedBooking, sizeof(updatedBooking), "ID : %d Train_No : %d Name : %s From : %s To : %s Cost : %d Time : %s\n", generateRandomID(0), _T.No, _T.Name, _T.From, _T.To, _T.Cost, _T.Time);
                    fprintf(tempFile, "No : %d Name : %s From : %s To : %s Cost : %d Time : %s Slots : %d\n",
                            _T.No, _T.Name, _T.From, _T.To, _T.Cost, _T.Time, _T.Slots);
                    system("cls");
                    printf("\n\nTicket booked successfully for Train No %d\n", T.Train_No);
                }
                else
                {
                    printf("\n\nSorry!, No Available Seats for Train No %d.\n", T.Train_No);
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

    if (found && !invalidTrainNo)
    {
        remove("txtFiles/trains_data.txt");
        rename("txtFiles/tempFile.txt", "txtFiles/trains_data.txt");

        BookFile = fopen("txtFiles/users.txt", "r+");
        if (BookFile == NULL)
        {
            printf("Error opening users.txt file!\n");
            return;
        }

        tempUserFile = fopen("txtFiles/tempUserFile.txt", "w");
        if (tempUserFile == NULL)
        {
            printf("Error creating tempUserFile.txt file!\n");
            fclose(BookFile);
            return;
        }

        char userLine[300];
        int insideBookedSection = 0;

        while (fgets(userLine, sizeof(userLine), BookFile))
        {
            if (strstr(userLine, "id :"))
            {
                int userID;
                sscanf(userLine, "id : %d", &userID);

                if (userID == ID)
                {
                    fprintf(tempUserFile, "%s", userLine);

                    while (fgets(userLine, sizeof(userLine), BookFile))
                    {
                        if (strstr(userLine, "Booked :"))
                        {
                            insideBookedSection = 1;
                            fprintf(tempUserFile, "%s", userLine);
                            break;
                        }
                        else
                        {
                            fprintf(tempUserFile, "%s", userLine);
                        }
                    }

                    if (insideBookedSection)
                    {
                        fprintf(tempUserFile, "%s", updatedBooking);
                        while (fgets(userLine, sizeof(userLine), BookFile))
                        {
                            fprintf(tempUserFile, "%s", userLine);
                        }
                    }
                }
                else
                {
                    fprintf(tempUserFile, "%s", userLine);
                }
            }
            else
            {
                fprintf(tempUserFile, "%s", userLine);
            }
        }

        fclose(BookFile);
        fclose(tempUserFile);

        remove("txtFiles/users.txt");
        rename("txtFiles/tempUserFile.txt", "txtFiles/users.txt");
    }
    else
    {
        printf("\nInvalid Train No.\n");
        remove("txtFiles/tempFile.txt");
    }

    printf("\n\nEnter Any Key to Exit...");
    getchar();
    getchar();
    system("cls");
    Home();
}
