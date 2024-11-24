#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "railway_main.h"

int RandomID() {
    return (rand() % 9000) + 1000;
}

int generateRandomID() {
   
    srand(time(0));

    return RandomID();
}
