#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "railway_main.h"
#include <windows.h>

struct Train
{
    int No;
    char Name[20];
    char From[20];
    char To[20];
    int Cost;
    char Time[10];
    int Slots;
} T;


void AddTrain()
{
    FILE *fptr;

    printf("\n\nEnter Train Name: ");
    scanf("%s", &T.Name);

    printf("\n\nEnter Train Departure: ");
    scanf("%s", &T.From);

    printf("\n\nEnter Train Destination: ");
    scanf("%s", &T.To);

    printf("\n\nEnter Train Ticket Cost: ");
    scanf("%d", &T.Cost);

    printf("\n\nEnter Train Departure Time: ");
    scanf("%s", &T.Time);

    printf("\n\nEnter Train Available Slots: ");
    scanf("%d", &T.Slots);

    if (strlen(T.Name) > 0 && strlen(T.From) > 0 && strlen(T.To) > 0 && T.Cost > 0 && strlen(T.Time) > 0 && T.Slots > 0)
    {
        int uniqueID = 0;

        while (!uniqueID)
        {
            T.No = generateRandomID(3);
            uniqueID = checkUniqueID(T.No);
        }

        fptr = fopen("txtFiles/trains_data.txt", "a");

        fprintf(fptr, "\nNo : %d Name : %s From : %s To : %s Cost : %d Time : %s Slots : %d", T.No, T.Name, T.From, T.To, T.Cost, T.Time, T.Slots);

        fclose(fptr);

        printf("\nAdding Train...!");
        Sleep(1000);
        printf("\n\nTrain Added Successfully.");
    }
    else
    {
        printf("\nInvalid Inputs..!");
    }
}