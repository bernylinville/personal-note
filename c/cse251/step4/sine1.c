/*
 * Simple program to experiment with looping
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    double angle;
    int numSteps = 20;
    double maxAngle = M_PI * 2;
    double sinVal;
    int i;
    int j;
    float numSpaces;

    for(i = 0; i <= numSteps;i++) {
        angle = (double)i / numSteps * maxAngle;
        sinVal = sin(angle);
        numSpaces = 30 + sinVal * 30;
        printf("%3d: %5.2f ", i, angle);
        for (j = 0; j < numSpaces; j++) {
            printf(" ");
        }
        puts("*");
    }
}
