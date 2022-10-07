#include <stdio.h>
#include <stdlib.h>

/*
 * 6-Tupel:
 * E = {0,1}
 * A = {0,1}
 * Z,Q = {q1}
 * q0 = 1
 * f = E x Q --> A
 * g = E x Q --> Q
 */

const int g[2][2] = {{1,0}, {1,1}};
const int f[2][2] = {{0,1}, {0,0}};

int main(void) {
    char e;
    int z = 0;

    while (1) {
        if(scanf("%c", &e) == EOF) {
            printf("\n");
            exit(0);
        } else if( e >='0' && e <= '9') {
            e = '1';
        } else {
            e = '0';
        }
        printf ("%i", f[z][e-'0']); fflush(stdout);
        z = g[z][(e=='0'?0:1)];
    }
    return 0;
}