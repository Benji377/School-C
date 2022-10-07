#include <stdio.h>
#include "matrix.h"

int main() {
    matrix_t a, b;
    for(int i = 0; i <= a.spalten; i++) {
        for(int j = 0; j <= a.zeilen; j++) {
            a.matrix[i][j] = 0;
        }
    }
    for(int i = 0; i <= b.spalten; i++) {
        for(int j = 0; j <= b.zeilen; j++) {
            b.matrix[i][j] = 1;
        }
    }
    matrix_t added = matrix_add(a,b);
    matrix_t subbed = matrix_sub(a,b);
    matrix_t multinum = matrix_mult_num(a, 10);
    printf("%f\n", added.matrix[0][0]);
    printf("%f\n", subbed.matrix[0][0]);
    printf("%f\n", multinum.matrix[0][0]);
    return 0;
}