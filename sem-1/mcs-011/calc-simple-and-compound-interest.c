#include <math.h>
#include <stdio.h>

double calc_simple_interest(double principal, double rate, double time) {
    return principal * rate * time;
}

double calc_compound_interest(double principal, double rate, double compounding_frequency, double time) {
    double amount = principal * pow(1 + rate/compounding_frequency, compounding_frequency * time);
    double interest = amount - principal;
    return interest;
}


int main() {
    double p, r, c_f, t;
    char option;

    printf("What do you want to calculate?\nA. Simple interest\nB. Compound interest\n(Enter A or B): ");
    scanf(" %c", &option);

    switch (option) {
        case 'A':
            printf("Enter principal, rate and time in that order: ");
            scanf(" %lf %lf %lf", &p, &r, &t);
            printf("The simple interest is %lf\n", calc_simple_interest(p, r, t));
            break;

        case 'B':
            printf("Enter principal, rate, compounding frequency and time in that order: ");
            scanf(" %lf %lf %lf %lf", &p, &r, &c_f, &t);
            printf("The compound interest is %lf\n", calc_compound_interest(p, r, c_f, t));
            break;

        default:
            printf("You entered wrong option!");
    }

    return 0;
}