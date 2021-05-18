#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "transistors.h"

/*
 * Name :  < insert name here >
 * Description : Simple transistor description example program
*/


int main()
{
    int i;
    Tran trans[3];

    printf("transistors!\n");

    for(i=0;  i<3;  i++)
    {
        trans[i] = InputTransistor();
    }

    for (i = 0; i < 3; i++)
    {
        printf("\nThe transistors:\n");
        DisplayTransistor(trans[i]);
    }
}
