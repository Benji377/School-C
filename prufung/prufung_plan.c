#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    FILE *fp;
    int anzahl = 15;
    fp = fopen("3ib.txt", "r");
    char name[anzahl][100];
    for(int i = 0; i < anzahl; i++) {
        fgets(name[i], 99, fp);
    }
    printf("Was ist: %s", name[0]);
    fclose(fp);

    fp = fopen("ausgabe.txt", "w");
    for(int i = 0; i < anzahl; i++) {
        //Hier kommt Zufall
        fprintf(fp, "%s", name[i]);
    }
    fclose(fp);

    return 0;
}

// Noch nicht implementiert
int random(anzahl) {
    srand(time(NULL));
    int random_number = (rand() % anzahl) + 1;
    return random_number;
}