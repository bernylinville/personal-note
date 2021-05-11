#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Name : combi
 * Program to determine combinations
 */

int Factorial(int n);
int Binomial(int n, int k);

int main ()
{
    int n, k, b;

    printf("Input n: ");
    scanf("%d", &n);
    if(n < 0)
    {
        printf("Must be greater than zero\n");
        exit(1);
    }

    printf("Input k: ");
    scanf("%d", &k);
    if(k < 0 || k > n)
    {
        printf("Must be between 0 and %d inclusive\n", n);
        exit(1);
    }

    // b = Factorial(n) / (Factorial(k) * Factorial(n - k));
    // printf("%d items taken %d ways is %d\n", n,k,b);
    b = Binomial(n, k);
    printf("%d items taken %d ways is %d\n", n, k, b);
}

int Factorial(int n)
{
    int f = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int Binomial(int n, int k)
{
    int c;
    c = Factorial(n - 1) / (Factorial(k - 1) * Factorial(n - k)) + Factorial(n - 1) / (Factorial(k) * Factorial(n - k - 1));
    return c;
}
