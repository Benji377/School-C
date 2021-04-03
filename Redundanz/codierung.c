#include<stdio.h>
#include<stdlib.h>

// Schaut anzahl 0 und 1 in File und gleicht diese aus damit sie gerade sind

int main(void) {
    FILE *fp;
    char c;
    char ch[20];
    int counter = 0;

    fp = fopen("../Redundanz/generator.txt", "r+");

    if(fp == NULL) {
        printf("file can't be opened\n");
        exit(1);
    }

    while((c = fgetc(fp)) != EOF) {
        printf("%c", c);
        counter++;
        if(counter%8 == 0) {
            // Zum testen
            printf("B");
        }
    }
    fclose(fp);
    return 0;
}