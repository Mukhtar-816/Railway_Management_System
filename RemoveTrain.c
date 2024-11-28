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

void RemoveTrain()
{
    FILE *fptr, *updatedTemp;
    int ID, found = 0;

    ViewTrains();

    printf("\n\nEnter Train ID: ");
    scanf("%d", &ID);

    if (ID > 0)
    {

        printf("\nChecking Train...!");
        Sleep(1000);


        fptr = fopen("txtFiles/trains_data.txt", "r");
        updatedTemp = fopen("txtFiles/updatedtemp.txt", "w");
        
        char tempLine[100];

        while (fgets(tempLine, sizeof(tempLine), fptr))
        {
            int TrainID;

            if (strstr(tempLine, "No :"))
            {
                sscanf(tempLine, "No : %d", &TrainID);
                if (TrainID == ID)
                {
                    printf("\n\nThe Train has been removed successfully!");
                    found = 1;
                }
                else
                {
                    fprintf(updatedTemp, "%s", tempLine);
                }
            }
            else
            {
                fprintf(updatedTemp, "%s", tempLine);
            }
        }

        fclose(fptr);
        fclose(updatedTemp);

        if (found){
            remove("txtFiles/trains_data.txt");
            rename("txtFiles/updatedtemp.txt", "txtFiles/trains_data.txt");
        }
        else {
            printf("\nTrain not found");
            remove("txtFiles/updatedtemp.txt");
        }

    }
    else
    {
        printf("\nInvalid Inputs..!");
    }
}