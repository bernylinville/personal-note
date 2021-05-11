/*
 * Simple program to experiment with looping
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    double angle;
    int numSteps;
    double maxAngle = M_PI * 2;
    double sinVal;
    double cosVal;
    int i;
    int j;
    double numSpaces;
    do {
        printf("Input the number of steps: ");
        scanf("%d",&numSteps);
        if (numSteps < 2) {
            exit(1);
        }
        for(i = 0; i <= numSteps;i++) {
            angle = (double)i / numSteps * maxAngle;
            sinVal = sin(angle);
            cosVal = cos(angle);
            numSpaces = 30 + sinVal * 30;
            printf("%3d: %5.2f ", i, angle);
            for (j = 0; j < numSpaces; j++) {
                printf(" ");
            }
            if ((1-fabs(sinVal)) < 0.01) {
                puts("*");
            }
            else if (cosVal < 0) {
                puts("/");
            }
            else {
                puts("\\");
            }
        }
    } while (true);
}
