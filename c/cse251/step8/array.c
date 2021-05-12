#include <stdio.h>

/*
 * Name : <Insert name>
 * Program to experiment with arrays
 */

#define NumMovies 10
#define MaxGrosses 5

int main()
{
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                         "Just Go With It", "Gnomeo and Juliet", "Drive Angry",
                         "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                         "True Grit"};
    double sum = 0;
    int highestGrossIndex = 0;
    double highestGross = 0;
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    int lessIndex = 0;

    for (int i = 0; i < NumMovies; i++) {
        printf("Movie %d: %33s: %.0f\n", i+1, names[i], gross[i]);
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);

    for (int i = 0; i < NumMovies; i++) {
        if (gross[i] > highestGross) {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

    for (int i = 0; i < MaxGrosses; i++) {
        if (highestGross > maxGross[i]) {
            lessIndex = i;
        }
    }
    if (lessIndex == 0) {
        puts("No film made less than 500000");
    }
    else {
        printf("The highest gross less than %.0f is %s at %.0f\n", maxGross[lessIndex], names[highestGrossIndex], highestGross);
    }
}
