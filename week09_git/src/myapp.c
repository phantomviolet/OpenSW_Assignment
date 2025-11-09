#include <stdio.h>

double calculate(char *op, double a, double b) {
    printf("Calculating.....\n");
}

int main() {
    double a, b;
    char op[3];

    printf("~~~ Whlcome to my calculator ~~~\n\n");
    printf("Emter expression (e.g. 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Resi;t = %.2lf\n", calculate(op, a, b));

    return 0;
}