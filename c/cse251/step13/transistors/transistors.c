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
    Tran t1;

    printf("transistors!\n");

    t1 = InputTransistor();

    DisplayTransistor(t1);

}
