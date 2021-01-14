#include <stdio.h>

struct vektor_s {
    float x;
    float y;
};



float vektsum() {
    struct vektor_s punkt_p, punkt_q, summe;
    printf("Erster Punkt(X und Y):");
    scanf("%f %f", &punkt_p.x, &punkt_p.y);

    printf("Zweiter Punkt(X und Y):");
    scanf("%f %f", &punkt_q.x, &punkt_q.y);

    summe.x = punkt_p.x + punkt_q.x;
    summe.y = punkt_p.y + punkt_q.y;
    printf("Summe: x=%f y=%f", summe.x, summe.y);
    return 0;
}

float vektprod() {
    struct vektor_s punkt_p, punkt_neu;
    float zahl;

    printf("Punkt eingeben(X und Y):");
    scanf("%f %f", &punkt_p.x, &punkt_p.y);
    printf("Zahl eingeben:");
    scanf("%f", &zahl);

    punkt_neu.x = punkt_p.x * zahl;
    punkt_neu.y = punkt_p.y * zahl;
    printf("Produkt: x=%f y=%f", punkt_neu.x, punkt_neu.y);

    return 0;
}

int main() {
    int eingabe;
    printf("Wähle Funktion(0=Summe, 1=Produkt:");
    scanf("%i", &eingabe);

    if (eingabe == 0) {
        vektsum();
    } else if (eingabe == 1) {
        vektprod();
    } else {
        printf("Error");
    }

    return 0;
}