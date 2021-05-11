#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
 * Simple lunar lander program.
 * By:  <berny>
 */

int main()
{
    double altitude = 100; // Meters
    double velocity = 0; // Meters per second
    double fuel = 100; // Kilograms
    double power = 1.5; // Acceleration per pound of fuel
    double gravity = -1.63; // Moon gravity in m/s^2
    double burn; // Amount of fuel to burn
    bool valid; // Valid data entry flag
    int time; // landed in how many seconds

    printf("Lunar Lander - (c) 2021, by <berny>\n");

    while (altitude > 0) {
        printf("Altitude: %.2f\n", altitude);
        printf("Velocity: %.2f\n", velocity);
        printf("You have %.1f kilograms of fuel\n", fuel);

        do {
            valid = false;   // Assume invalid until we know otherwise

            printf("How much fuel would you like to burn: ");
            scanf("%lf", &burn);

            if (burn < 0) {
                puts("You can't burn negative fuel");
            }
            else if (burn > 5) {
                puts("You can't burn more than 5 kilograms per second");
            }
            else if (burn > fuel) {
                puts("You can't burn fuel you don't have");
            }
            else {
                printf("Burning %.1f kilograms of fuel\n", burn);
                valid = true;
            }
        } while (!valid);

        velocity = velocity + gravity + power * burn;
        altitude -= velocity;
        fuel -= burn;

        printf("You landed with a velocity of %.2f\n", velocity);

        if(fabs(velocity) > 3) {
            printf("Your next of kin have been notified\n");
        }

        time++;
    }

    printf("You have %.1f kilograms of fuel\n", fuel);
    printf("Landing: Time = %d seconds", time);
}
