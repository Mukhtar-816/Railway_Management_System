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


