#include <stdio.h>
#include <string.h>
#include "railway_main.h"
#include <windows.h>

struct TrainsData
{
    int No;
    char Name[20];
    char From[20];
    char To[20];
    int Cost;
    int Slots;
    char Time[10];
} Td;

void ViewTrains()
// int main()
{
    FILE *fptr;
    fptr = fopen("txtFiles/trains_data.txt", "r");
    char tempLine[100];

    printf("\n Train Shedule:- \n\n");
    printf("=================================================================================================\n");
    printf("| Train No |  |  Train Name  |  |   From    |  |    To    |  |  Cost  |  |  Time  |  |  Slots  |\n");
    printf("=================================================================================================\n");
    while (fgets(tempLine, sizeof(tempLine), fptr))
    {
        if (sscanf(tempLine, "No : %d Name : %s From : %s To : %s Cost : %d Time : %s Slots : %d", &Td.No, &Td.Name, &Td.From, &Td.To, &Td.Cost, &Td.Time, &Td.Slots))
        {
            printf("| %-8d |  | %-12s |  | %-8s |  | %-9s |  | %-6d |  | %-6s |  | %-7d | \n", Td.No, Td.Name, Td.From, Td.To, Td.Cost, Td.Time, Td.Slots);
        }
    }
    printf("=================================================================================================\n");
    fclose(fptr);

    
}