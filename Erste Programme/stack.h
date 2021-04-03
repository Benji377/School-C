#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int maxsize;
    int top;
    int *items;
};

struct stack* newStack(int capacity) {
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}
int size(struct stack *pt) {
    return pt->top + 1;
}

int isEmpty(struct stack *pt) {
    return pt->top == -1;
}

int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;
}

int peek(struct stack *pt) {
    if (!isEmpty(pt))
        return pt->items[pt->top];
    else
        exit(EXIT_FAILURE);
}

void push(struct stack *pt, int x);
int pop(struct stack *pt);

#endif