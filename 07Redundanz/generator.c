#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int bytes = 1;

    printf("Anzahl bytes: ");
    scanf("%d", &bytes);

    FILE *fp;
    fp = fopen("../Redundanz/generator.txt", "w");

    if(fp == NULL) {
        printf("file can't be opened\n");
        exit(1);
    }
    for(int i = 0; i< bytes; i++) {
        int num = rand() % 2;
        //printf("Random Integer:\t%d\n", num);
        //printf("%d ", num);
        fprintf(fp, "%d",num);
    }
    fclose(fp);
    return 0;
}