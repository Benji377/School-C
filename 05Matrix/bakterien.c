#include "matrix.h"

int main (void) {
    matrix_t ergebnis;
    ergebnis.zeilen = 4;
    ergebnis.spalten = 4;
    int vektor = 10;


    ergebnis = matrix_mult_num(ergebnis, vektor);


    return 0;
}