#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>


int main() {
    char s[1000];
    int zeichen;
    struct stack *pt = newStack(100);
    printf("Eingabe:");
    fgets(s, 999, stdin);
    s[strlen(s)-1] = 0;
    const char *teil = strtok(s, " ");
    while ( teil != NULL) {
        if (teil[0] != '+' && teil[0] != '-' && teil[0] != '/' && teil[0] != '*') {
            sscanf(teil, " %d", &zeichen);
            push(pt, zeichen);
        } else {
            int r = pop(pt);
            int l = pop(pt);
            switch (teil[0]) {
                case '+': push(pt, l+r); break;
                case '-': push(pt,l-r); break;
                case '/': push(pt,l/r); break;
                case '*': push(pt,l*r); break;
                default: printf("Error");
            }
        }
        teil = strtok(NULL, " ");
    }
    int ergebnis = pop(pt);
    printf("Ergebnis: %i\n", ergebnis);
    //push(pt, ergebnis);
}

int pop(struct stack *pt) {
    if (isEmpty(pt))
    {
        printf("UnderFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    printf("Removing %d\n", peek(pt));
    return pt ->items[pt->top--];
}

void push(struct stack *pt, int x) {
    if (isFull(pt))
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    printf("Inserting %d\n", x);
    pt->items[++pt->top] = x;
}