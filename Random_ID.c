#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "railway_main.h"

int RandomID(int lim)
{
    if (lim == 3)
    {
        return (rand() % 900) + 100; 
    }
    else
    {
        return (rand() % 9000) + 1000;
    }
}

int generateRandomID(int lim)
{
    srand(time(0)); 
    return RandomID(lim); 
}
