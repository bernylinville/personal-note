#include "stdio.h"

int main()
{
    float latitude;
    float longitude;
    char info[80];
    // %79[^\n] every character up to the end of the line.
    // == 3 means The scanf() function returns the number of values it was able to read.
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
        if ((latitude > 26) && (latitude < 34))
            if ((longitude > -76) && (longitude < -64))
                printf("%f,%f,%s\n", latitude, longitude, info);
    return 0;
}
