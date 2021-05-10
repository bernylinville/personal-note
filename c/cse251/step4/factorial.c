/*
 * Simple program to experiment with looping
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int f ; // Number we compute the factorial of

    while (true) {
        int fac = 1; // Initial value of factorial
        printf("Number to compute the factorial of: ");
        scanf("%d", &f);

        if (f < 0) {
            break;
        }

        int f_old = f;

        while(f > 0) {
            fac = fac * f;
            f--;
        }

        printf("%d! = %d\n", f_old, fac);
    }
}
