#include <stdio.h>

int main() {
    float a, b;
    printf("Erstes Argument eingeben:");
    scanf("%f", &a);
    printf("Zweite Argument eingeben:");
    scanf("%f", &b);

    printf("%f + %f = %f \n", a, b, (float)a+b);
    printf("%f - %f = %f \n", a, b, (float)a-b);
    printf("%f / %f = %f \n", a, b, (float)a/b);
    printf("%f * %f = %f \n", a, b, (float)a*b);

    return 0;
}