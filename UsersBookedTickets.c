#include <stdio.h>
#include <string.h>
#include "railway_main.h"
#include <windows.h>

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

void ShowUsersBookedTicket()
// int main()
{

    FILE *user, *fptr;
    user = fopen("txtFiles/currentuser.txt", "r");
    char str[20], tempLine[100];
    int ID;
    while (fgets(str, sizeof(str), user))
    {
        sscanf(str, "userID : %d", &ID);
    }
    fclose(user);

    fptr = fopen("txtFiles/users.txt", "r");

    int userID;
    printf("\nYour Train Tickets:- \n\n");
    printf("==================================================================================================\n");
    printf("| Ticket ID |  | Train No |  |  Train Name  |  |   From    |  |    To    |  |  Cost  |  |  Time  |\n");
    printf("==================================================================================================\n");
    while (fgets(tempLine, sizeof(tempLine), fptr))
    {
        sscanf(tempLine, "id : %d", &userID);
        if (userID == ID)
        {
            if (strstr(tempLine, "Booked :"))
            {
                
                while (fgets(tempLine, sizeof(tempLine), fptr))
                {
                    if (strstr(tempLine, "Cancelled :") || tempLine[0] == '\n' || strstr(tempLine, "id :"))
                    {
                        break;
                    }
                    if (sscanf(tempLine, "ID : %d Train_No : %d Name : %s From : %s To : %s Cost : %d Time : %s ", &Td.ID, &Td.No, &Td.Name, &Td.From, &Td.To, &Td.Cost, &Td.Time))
                    {
                        printf("| %-9d |  | %-8d |  | %-12s |  | %-9s |  | %-9s |  | %-6d |  | %-6s |  \n", Td.ID, Td.No, Td.Name, Td.From, Td.To, Td.Cost, Td.Time);
                    }
                }
            }
        }
    }
    printf("==================================================================================================\n");
    fclose(fptr);
}
