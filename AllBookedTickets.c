#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "railway_main.h"

struct TrainsData
{
    int ID;
    int No;
    char Name[20];
    char From[20];
    char To[20];
    int Cost;
    char Time[10];
} Td;

void ViewAllBookings()
{
    FILE *fptr;
    char tempLine[100];

    fptr = fopen("txtFiles/users.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening user data file.\n");
    }

    printf("\nAll Users' Train Tickets:- \n\n");
    printf("=============================================================================================================================\n");
    printf("| User ID  | | User Name | | Ticket ID |  | Train No |  |  Train Name  |  |   From    |  |    To    |  |  Cost  |  |  Time  |\n");
    printf("=============================================================================================================================\n");

    int currentUserID = 0;
    int foundBooking = 0;

    while (fgets(tempLine, sizeof(tempLine), fptr))
    {
        int userID;
        char username[20];

        if (sscanf(tempLine, "id : %d", &userID) == 1)
        {
            if (fgets(tempLine, sizeof(tempLine), fptr) && sscanf(tempLine, "username : %s", username) == 1)
            {
                while (fgets(tempLine, sizeof(tempLine), fptr))
                {
                    if (strstr(tempLine, "Cancelled :") || strstr(tempLine, "id :") || tempLine[0] == '\n')
                    {
                        break;
                    }

                    if (strstr(tempLine, "Booked :"))
                    {
                        while (fgets(tempLine, sizeof(tempLine), fptr))
                        {
                            if (strstr(tempLine, "id :") || strstr(tempLine, "Cancelled :") || tempLine[0] == '\n')
                            {
                                break;
                            }

                            if (sscanf(tempLine, "ID : %d Train_No : %d Name : %s From : %s To : %s Cost : %d Time : %s ",
                                       &Td.ID, &Td.No, Td.Name, Td.From, Td.To, &Td.Cost, Td.Time) == 7)
                            {
                                printf("| %-8d | | %-9s | | %-9d | | %-9d |  | %-12s |  | %-9s |  | %-9s |  | %-6d |  | %-5s |\n",
                                       userID, username, Td.ID, Td.No, Td.Name, Td.From, Td.To, Td.Cost, Td.Time);
                                foundBooking = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (!foundBooking)
    {
        printf("| %-8s | No bookings found. |\n", "");
    }

    printf("=============================================================================================================================\n");

    fclose(fptr);
}
