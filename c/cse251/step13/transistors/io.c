#include <stdio.h>
#include <string.h>

#include "transistors.h"

void DisplayTransistor(struct Transistor tran)
{
    printf("Number: %s\n", tran.number);

    switch(tran.type)
    {
    case NPN:
        printf("Type: NPN\n");
        break;

    case PNP:
        printf("Type: PNP\n");
        break;
    }

    switch(tran.caseStyle)
    {
    case TO18:
        printf("caseStyle: TO18\n");
        break;

    case TO92A:
        printf("caseStyle: TO92A\n");
        break;

    case TO92C:
        printf("caseStyle: TO92C\n");
        break;

    case TO220:
        printf("caseStyle: TO220\n");
        break;

    case TO39:
        printf("caseStyle: TO39\n");
        break;
    }

    printf("pMax: %.3f\n", tran.pmax);
    printf("icMax: %.3f\n", tran.icmax);
}

struct Transistor InputTransistor()
{
    struct Transistor t1;

    printf("Please input transistor's number: ");
    InputString(t1.number, sizeof(t1.number));
    t1.type = InputTransistorType("Input type: ");
    t1.caseStyle = InputTransistorStyle("Input caseStyle: ");
    t1.pmax = InputPositiveValue("Input pMax: ");
    t1.icmax = InputPositiveValue("Input icMax: ");

    return t1;
}

void InputString(char *str, int max)
{
    char buffer[100];

    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';

    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max-1] = '\0';
}

double InputPositiveValue(char *prompt)
{
    char buffer[100];
    double value = 0;

    do {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        sscanf(buffer, "%lf", &value);
    } while (value <= 0);

    return value;
}

int InputTransistorType(char *prompt)
{
    char buffer[100];
    int transistorType;

    do {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        if(strcmp(buffer, "PNP") == 0) {
            transistorType = PNP;
        }
        if(strcmp(buffer, "NPN") == 0) {
            transistorType = NPN;
        }

        // sscanf(buffer, "%d", &transistorType);
    } while (transistorType != NPN && transistorType != PNP);

    return transistorType;
}

int InputTransistorStyle(char *prompt)
{
    char buffer[100];
    int transistorStyle;

    do {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        if(strcmp(buffer, "TO18") == 0) {
            transistorStyle = TO18;
        }
        if(strcmp(buffer, "TO92A") == 0) {
            transistorStyle = TO92A;
        }
        if(strcmp(buffer, "TO92C") == 0) {
            transistorStyle = TO92C;
        }
        if(strcmp(buffer, "TO220") == 0) {
            transistorStyle = TO220;
        }
        if(strcmp(buffer, "TO39") == 0) {
            transistorStyle = TO39;
        }

        // sscanf(buffer, "%d", &transistorType);
    } while (transistorStyle < 1 && transistorStyle > 5);

    return transistorStyle;
}
