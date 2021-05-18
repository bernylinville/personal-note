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
    struct Transistor t1;

    printf("transistors!\n");

    strcpy(t1.number, "2N3053");
    t1.type = NPN;
    t1.caseStyle = TO39;
    t1.pmax = 0.500;    /* 500mw */
    t1.icmax = 0.700;   /* 700ma */

    DisplayTransistor(t1);

}
