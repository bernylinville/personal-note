#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

/*
 * Name :  < insert name here >
 * Description : Simple transistor description example program
*/


int main()
{
    int i;
    Tran *trans;
    int numTrans = 0;
    char response[10];

    printf("transistors!\n");

    /* Allocate space for one transistor */
    trans = malloc(sizeof(Tran));
    numTrans = 1;

    /* Input the transistor */
    trans[0] = InputTransistor();

    printf("Would you like to enter another transistor (Y/N)? ");
    AnotherTransistor(response, sizeof(response));

    if (strcmp(response, "y") == 0) {
        /* Increase the space by one transistor */
        trans = realloc(trans, sizeof(Tran) * (numTrans + 1));
        numTrans++;

        trans[numTrans-1] = InputTransistor();
    }

    if (strcmp(response, "n") == 0) {
        /* Output the transistors */
        printf("\nThe transistors:\n");
        for(i=0;  i<numTrans;  i++)
        {
            DisplayTransistor(trans[i]);
        }
    }

    /* Free the memory */
    free(trans);
}
