#include <stdio.h>
#include "matrix.h"
#include <math.h>


int main(void) {
    matrix_t drehmatrix, result;
    drehmatrix.zeilen = 2;
    drehmatrix.spalten = 2;
    double alpha = 0;

    drehmatrix.matrix[0][0] = cos(alpha);
    drehmatrix.matrix[0][1] = sin(alpha) * -1;
    drehmatrix.matrix[1][0] = sin(alpha);
    drehmatrix.matrix[1][1] = cos(alpha);

    result.zeilen = 2;
    result.spalten = 1;
    result.matrix[0][0] = 1;
    result.matrix[1][0] = 1;


}