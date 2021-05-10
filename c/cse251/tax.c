#include <stdio.h>
#include <stdlib.h>

int main() {
    float annualIncome;
    float taxOwed;
    int numberChoices;
    int childrenNumbers;
    int dependents;
    int deduction;
    float totalDeductions;
    float taxableIncome;
    printf("Enter your annual income: ");
    scanf("%f", &annualIncome);

    if (annualIncome < 9350) {
        taxOwed = 0;
        exit(1);
    }

    printf("What is your filing status?\n1) single\n2) married filing jointly\n3) married filing separately\nPlease enter a number: ");
    scanf("%d" ,&numberChoices);

    switch (numberChoices) {
        case 1:
        case 3:
            dependents = 1;
            deduction = 5700;
            totalDeductions = deduction + 3650;
            taxableIncome = annualIncome - totalDeductions;
            break;
        case 2:
            printf("How many children do you have? ");
            scanf("%d" ,&childrenNumbers);
            dependents = 2 + childrenNumbers;
            deduction = 11400;
            totalDeductions = deduction + dependents * 3650;
            taxableIncome = annualIncome - totalDeductions;
            break;
        default:
            break;
    }

    if (taxableIncome <= 16750) {
        taxOwed = taxableIncome * 0.1;
    }
    else if ((taxableIncome > 16750) && (taxableIncome <= 68000)) {
        taxOwed = 1675 + (taxableIncome - 16750) * 0.15;
    }
    else if ((taxableIncome > 68000) && (taxableIncome <= 137300)) {
        taxOwed = 9362.5 + (taxableIncome - 68000) * 0.25;
    }
    else {
        taxOwed = 26687.5 + (taxableIncome - 137300) * 0.28;
    }

    printf("%.2f", taxOwed);
    return 0;
}
