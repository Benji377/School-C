#include <stdio.h>
#include "fibonacci.h"

int main() {
    int n;
    int i;
    printf("Eingabe:");
    scanf("%i", &n);

    printf("Fibbonacci of %d: " , n);

    for(i = 0;i<n;i++) {
        printf("%d ",fibbonacci(i));
    }
}
