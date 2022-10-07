#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    int max_number, random_number;
    char nochmals;
    bool aktiv = true;
    srand(time(NULL));

    printf("Wie viele Schüler sind anwesend? ");
    scanf(" %i", &max_number);

    while (aktiv) {
        if (max_number > 0) {
            random_number = (rand() % max_number) + 1;
            printf("Gewürfelte Zahl: %i \n", (int)random_number);
            printf("Nochmals Würfeln?(j/n): ");
            scanf(" %c", &nochmals);
            if (nochmals != 'j') {
                aktiv = false;
            }
        } else if (max_number < 0) {
            printf("Nicht gültig \n");
            aktiv = false;
        } else {
            printf("Keine Schüler sind anwesend \n");
            aktiv = false;
        }
    }
    return 0;
}